#include <omnetpp.h>
#include "openflow/openflow/controller/OF_Controller.h"

#include "inet/applications/tcpapp/GenericAppMsg_m.h"
#include "openflow/openflow/protocol/OpenFlow.h"
#include "openflow/messages/Open_Flow_Message_m.h"
#include "openflow/messages/OFP_Packet_Out_m.h"
#include "inet/transportlayer/contract/tcp/TCPCommand_m.h"
#include "openflow/messages/OFP_Flow_Mod_m.h"
#include "openflow/messages/OFP_Features_Request_m.h"
#include "openflow/messages/OFP_Features_Reply_m.h"
#include "openflow/messages/OFP_Stats_Reply_m.h"
#include "inet/transportlayer/tcp/TCPConnection.h"
#include "openflow/messages/OFP_Initialize_Handshake_m.h"
#include "openflow/controllerApps/AbstractControllerApp.h"

#include "inet/networklayer/common/InterfaceTable.h"
#include "inet/networklayer/common/L3AddressResolver.h"

using namespace std;

#define MSGKIND_BOOTED 100
#define MSGKIND_EXTRACT_TOPO 1001
namespace openflow{

Define_Module(OF_Controller);



OF_Controller::OF_Controller(){

}

OF_Controller::~OF_Controller(){
    for(auto&& msg : this->msgList) {
      delete msg;
    }
    this->msgList.clear();
}

void OF_Controller::initialize(){
    //register signals
    PacketInSignalId =registerSignal("PacketIn");
    PacketOutSignalId =registerSignal("PacketOut");
    PacketHelloSignalId =registerSignal("PacketHello");
    PacketFeatureRequestSignalId = registerSignal("PacketFeatureRequest");
    PacketFeatureReplySignalId = registerSignal("PacketFeatureReply");
    PacketExperimenterSignalId = registerSignal("PacketExperimenter");
    BootedSignalId = registerSignal("Booted");
    TopologySignalId = registerSignal("Topology");
    PacketStatsReplySignalId = registerSignal("PacketStatsReply");

    //stats
    queueSize = registerSignal("queueSize");
    waitingTime = registerSignal("waitingTime");
    numPacketIn=0;

    lastQueueSize =0;
    lastChangeTime=0.0;

    //parameters
    serviceTime = par("serviceTime");
    busy = false;

    // TCP socket; listen on incoming connections
    const char *address = par("address");
    int port = par("port");
    socket.setOutputGate(gate("tcpOut"));
    socket.setDataTransferMode(TCP_TRANSFER_OBJECT);
    socket.bind(address[0] ? L3Address(address) : L3Address(), port);
    socket.listen();

    //schedule booted message
    cMessage *booted = new cMessage("Booted");
    booted->setKind(MSGKIND_BOOTED);
    scheduleAt(simTime() + par("bootTime").doubleValue(), booted);

    //schedule topology discovery
    cMessage *ExtractTopo = new cMessage("Topology Extraction");
    ExtractTopo->setKind(MSGKIND_EXTRACT_TOPO);
    scheduleAt(1.5 , ExtractTopo);

}


void OF_Controller::handleMessage(cMessage *msg){
    if (msg->isSelfMessage()) {
        if (msg->getKind()==MSGKIND_BOOTED){
            this->booted = true;
            emit(BootedSignalId, this);
        }else if (msg->getKind() == MSGKIND_EXTRACT_TOPO){
            const char *NodeType = " sdn4core.examples.tsnMtd.getnet.Host sdn4core.examples.tsnMtd.getnet.Switch sdn4core.examples.tsnMtd.getnet.EdgeSwitch";
            extractTopology(NodeType);
            extractSwitchInfoTable();
            extractHostProfileTable();
            extractHostSwMacTable();
            emit(TopologySignalId, this);
        }else{
            //This is message which has been scheduled due to service time
            //Get the Original message
            cMessage *data_msg = (cMessage *) msg->getContextPointer();
            emit(waitingTime,(simTime()-data_msg->getArrivalTime()-serviceTime));
            processQueuedMsg(data_msg);

            //delete the processed msg
            delete data_msg;

            //Trigger next service time
            if (msgList.empty()){
                busy = false;
            } else {
                cMessage *msgfromlist = msgList.front();
                msgList.pop_front();
                cMessage *event = new cMessage("event");
                event->setContextPointer(msgfromlist);
                scheduleAt(simTime()+serviceTime, event);
            }
            calcAvgQueueSize(msgList.size());
        }
        //delete the msg for efficiency
        delete msg;
    }else if (this->booted){
        //imlement service time
        if (busy) {
            msgList.push_back(msg);
        }else{
            busy = true;
            cMessage *event = new cMessage("event");
            event->setContextPointer(msg);
            scheduleAt(simTime()+serviceTime, event);
        }


        if(packetsPerSecond.count(floor(simTime().dbl())) <=0){
            packetsPerSecond.insert(pair<int,int>(floor(simTime().dbl()),1));
        } else {
            packetsPerSecond[floor(simTime().dbl())]++;
        }

        calcAvgQueueSize(msgList.size());
        emit(queueSize,static_cast<unsigned long>(msgList.size()));
    } else {
        // this is not a self message and we are not yet booted
        // ignore it.
        delete msg;
    }
}

void OF_Controller::calcAvgQueueSize(int size){
    if(lastQueueSize != size){
        double timeDiff = simTime().dbl() - lastChangeTime;
        if(avgQueueSize.count(floor(simTime().dbl())) <=0){
            avgQueueSize.insert(pair<int,double>(floor(simTime().dbl()),lastQueueSize*timeDiff));
        } else {
            avgQueueSize[floor(simTime().dbl())] += lastQueueSize*timeDiff;
        }
            lastChangeTime = simTime().dbl();
            lastQueueSize = size;
        }
}


void OF_Controller::processQueuedMsg(cMessage *data_msg){
    if (dynamic_cast<Open_Flow_Message *>(data_msg) != NULL) {
        Open_Flow_Message *of_msg = (Open_Flow_Message *)data_msg;
        ofp_type type = (ofp_type)of_msg->getHeader().type;

        switch (type) {
            case OFPT_FEATURES_REPLY:
                handleFeaturesReply(of_msg);
                break;
            case OFPT_HELLO:
                registerConnection(of_msg);
                sendHello(of_msg);
                sendFeatureRequest(data_msg);
                break;
            case OFPT_PACKET_IN:
                EV << "packet-in message from switch\n";
                handlePacketIn(of_msg);
                break;
            case OFPT_VENDOR:
                // the controller apps might want to implement vendor specific features so forward them.
                handleExperimenter(of_msg);
                break;
            case OFPT_STATS_REPLY:
                handleStatsReply(of_msg);
                break;

            default:
                break;
        }
    }
}


void OF_Controller::sendHello(Open_Flow_Message *msg){
    OFP_Hello *hello = new OFP_Hello("Hello");
    hello->getHeader().version = OFP_VERSION;
    hello->getHeader().type = OFPT_HELLO;
    hello->setByteLength(8);
    hello->setKind(TCP_C_SEND);

    emit(PacketHelloSignalId,hello);
    TCPSocket *socket = findSocketFor(msg);
    socket->send(hello);
}

void OF_Controller::sendFeatureRequest(cMessage *msg){
    OFP_Features_Request *featuresRequest = new OFP_Features_Request("FeaturesRequest");
    featuresRequest->getHeader().version = OFP_VERSION;
    featuresRequest->getHeader().type = OFPT_FEATURES_REQUEST;
    featuresRequest->setByteLength(8);
    featuresRequest->setKind(TCP_C_SEND);

    emit(PacketFeatureRequestSignalId,featuresRequest);
    TCPSocket *socket = findSocketFor(msg);
    socket->send(featuresRequest);
}

void OF_Controller::handleFeaturesReply(Open_Flow_Message *of_msg){
    EV << "OFA_controller::handleFeaturesReply" << endl;
    Switch_Info *swInfo= findSwitchInfoFor(of_msg);
    if(dynamic_cast<OFP_Features_Reply *>(of_msg) != NULL){
        OFP_Features_Reply * castMsg = (OFP_Features_Reply *)of_msg;
        swInfo->setMacAddress(castMsg->getDatapath_id());
        swInfo->setNumOfPorts(castMsg->getPortsArraySize());
        emit(PacketFeatureReplySignalId,castMsg);
    }
}

void OF_Controller::handlePacketIn(Open_Flow_Message *of_msg){
    EV << "OFA_controller::handlePacketIn" << endl;
    numPacketIn++;
    emit(PacketInSignalId,of_msg);
}

void OF_Controller::handleStatsReply(Open_Flow_Message *of_msg){
    EV << "OFA_controller::handleStatsReply" << endl;
    if(dynamic_cast<OFP_Stats_Reply *>(of_msg) != NULL){
        OFP_Stats_Reply * castMsg = (OFP_Stats_Reply *)of_msg;
        emit(PacketStatsReplySignalId,castMsg);
       }
}


void OF_Controller::sendPacketOut(Open_Flow_Message *of_msg, TCPSocket *socket){
    Enter_Method_Silent();
    take(of_msg);
    EV << "OFA_controller::sendPacketOut" << endl;
    emit(PacketOutSignalId,of_msg);
    socket->send(of_msg);
}


void OF_Controller::handleExperimenter(Open_Flow_Message* of_msg) {
    EV << "OFA_controller::handleExperimenter" << endl;
    emit(PacketExperimenterSignalId, of_msg);
}


void OF_Controller::registerConnection(Open_Flow_Message *msg){
    TCPSocket *socket = findSocketFor(msg);
    if(!socket){
        socket = new TCPSocket(msg);
        socket->setOutputGate(gate("tcpOut"));
        Switch_Info swInfo = Switch_Info();
        swInfo.setSocket(socket);
        swInfo.setConnId(socket->getConnectionId());
        swInfo.setMacAddress("");
        swInfo.setNumOfPorts(-1);
        swInfo.setVersion(msg->getHeader().version);
        switchesList.push_back(swInfo);
    }
}


TCPSocket *OF_Controller::findSocketFor(cMessage *msg) const{
    TCPCommand *ind = dynamic_cast<TCPCommand *>(msg->getControlInfo());
    if (!ind)
        throw cRuntimeError("TCPSocketMap: findSocketFor(): no TCPCommand control info in message (not from TCP?)");

    int connId = ind->getConnId();
    for(auto i=switchesList.begin(); i != switchesList.end(); ++i) {
        if((*i).getConnId() == connId){
            return (*i).getSocket();
        }
    }
    return NULL;
}


Switch_Info *OF_Controller::findSwitchInfoFor(cMessage *msg) {
    TCPCommand *ind = dynamic_cast<TCPCommand *>(msg->getControlInfo());
    if (!ind)
        return NULL;

    int connId = ind->getConnId();
    for(auto i=switchesList.begin(); i != switchesList.end(); ++i) {
        if((*i).getConnId() == connId){
            return &(*i);
        }
    }
    return NULL;
}

TCPSocket *OF_Controller::findSocketForChassisId(std::string chassisId) const{
    for(auto i=switchesList.begin(); i != switchesList.end(); ++i) {
        if(strcmp((*i).getMacAddress().c_str(),chassisId.c_str())==0){
            return (*i).getSocket();
        }
    }
    return NULL;
}

void OF_Controller::registerApp(AbstractControllerApp *app){
    apps.push_back(app);
}

std::vector<Switch_Info >* OF_Controller::getSwitchesList() {
    return &switchesList;
}

std::vector<AbstractControllerApp *>* OF_Controller::getAppList() {
    return &apps;
}

std::vector<Host_Profile >* OF_Controller::getHostsList() {
    return &_hostsList;
}


std::vector<int>* OF_Controller::getHostIndexes() {
    return &_hostIndexes;
}

int OF_Controller::getTopoIndex(int moduleid) {
    for(int i=0;i<_topology.getNumNodes();i++){
        if(moduleid==_topology.getNode(i)->getModuleId()){
            return i;
        }
    }
    return -1;
}




void OF_Controller::extractTopology(const char *NodeType){
    cout<<"---------------------"<<endl;
    cModule *mod  ;
    IInterfaceTable *ift ;
    MACAddress mac ;

    std::vector<std::string> nodeTypes = cStringTokenizer(NodeType).asVector();
    _topology.extractByNedTypeName(nodeTypes);
    cout << "cTopology found with " << _topology.getNumNodes() << " nodes\n";

    cout<<"Edge switches are:";
    for(int i=0;i<_topology.getNumNodes();i++){
        string ss=_topology.getNode(i)->getModule()->getFullName();

        if(ss.find("switch")!=std::string::npos){
            _switchIndexes.push_back(_topology.getNode(i)->getModuleId());
            std::ostringstream ss;
            ss << (_topology.getNode(i)->getModule()->getModuleType());
            string os=ss.str();


            //set sw topo index
            mod = _topology.getNode(i)->getModule();
            ift = L3AddressResolver().interfaceTableOf(mod);
            mac = ift->getInterface(0)->getMacAddress();
            for(auto s=switchesList.begin(); s != switchesList.end(); ++s) {
                if(MACAddress((*s).getMacAddress().c_str()) == mac){
                    (*s).setTopo_index(i);
                    if(os.find("EdgeSwitch")!=std::string::npos){// edgeswitch
                        _EdgeSwitches.push_back(_topology.getNode(i));
                        cout<<_topology.getNode(i)->getModule()->getFullName()<<" ";
                        (*s).IsEdge=true;
                    }
                    break;
                }
            }
        }
        else{
            _hostIndexes.push_back(_topology.getNode(i)->getModuleId());

            mod = _topology.getNode(i)->getModule();
            ift = L3AddressResolver().interfaceTableOf(mod);
            mac = ift->getInterface(0)->getMacAddress();

            Host_Profile hostProfile = Host_Profile();
            stringstream ss;
            ss << mac;
            hostProfile.setMacAddress(ss.str());

            //set own topo index
            hostProfile.setTopo_index(i);

            //get connected sw topo index
            int j=0;
            int links=_topology.getNode(i)->getNumInLinks();
            while(j<links){
                cTopology::Node * remoteNode=_topology.getNode(i)->getLinkIn(j)->getRemoteNode();
                string sh=remoteNode->getModule()->getFullName();
                if(sh.find("switch")!=std::string::npos){
                    //cout<<_topology.getNode(i)->getModule()->getFullName()<<" connected to "<<remoteNode->getModule()->getFullName()<<endl;
                    hostProfile.setConnectedSw_topo_index(getTopoIndex(remoteNode->getModuleId()));

                    //also add it to the related switch
                    mod = remoteNode->getModule();
                    ift = L3AddressResolver().interfaceTableOf(mod);
                    mac = ift->getInterface(0)->getMacAddress();
                    for(auto s=switchesList.begin(); s != switchesList.end(); ++s) {
                        if(MACAddress((*s).getMacAddress().c_str()) == mac){
                            (*s).connectedHostIndexes.push_back(i);
                            break;
                        }
                    }
                    break;
                }
                j+=1;
            }
            _hostsList.push_back(hostProfile);

        }
    }



    cout<<"\n---------------------"<<endl;
    //checkTopology();




}


void OF_Controller::checkTopology(){
    cout<<"---------------------"<<endl;


    for(int i=0;i<_topology.getNumNodes();i++){
        cout<<i<<"\t";
        cout<<_topology.getNode(i)->getModule()->getFullName()<<endl;

        cTopology::Node * current=_topology.getNode(i);
        for(int j = 0; j < current->getNumInLinks();j++)
            cout<<j<<"th link from "<<current->getLinkIn(j)->getRemoteNode()->getModuleId()<<endl;
        for(int j = 0; j < current->getNumOutLinks();j++)
            cout<<j<<"th link to "<<current->getLinkOut(j)->getRemoteNode()->getModuleId()<<endl;


        cout<<"---------------------"<<endl;
    }
}






void  OF_Controller::extractSwitchInfoTable(){
    //switchID-moduleID table
    cout<<"ModuleID\tTopo-index\tSwitchID\tConnectedHosts"<<endl;

    int j=0;
    for(auto i=switchesList.begin(); i != switchesList.end(); ++i) {
        _SwitchInfoTable[_switchIndexes[j]]=*i;
        j++;
    }

    std::vector<int> hosts;
    for (auto x : _SwitchInfoTable){
        cout << x.first  <<"\t"<< (x.second).getTopo_index()<<"\t"<<(x.second).getMacAddress()<<"\t";
        hosts=(x.second).connectedHostIndexes;
        for (auto h : hosts)
            cout<<h<<" ";
        cout<< endl;
    }
}

void  OF_Controller::extractHostProfileTable(){
    //hostMAC-moduleID table
    cout<<"ModuleID\tTopo-index\thostMAC\tConnectedSWTopoIndex"<<endl;

    int j=0;
    for(auto i=_hostsList.begin(); i != _hostsList.end(); ++i) {
        _HostProfileTable[_hostIndexes[j]]=*i;
        j++;
    }

    for (auto x : _HostProfileTable)
        cout << x.first  <<"\t"<< (x.second).getTopo_index()<<"\t"<< (x.second).getMacAddress()<<"\t"<< (x.second).getConnectedSw_topo_index()<< endl;

}


void OF_Controller::extractHostSwMacTable(){
    ofstream fs;
    string filename="/root/DynTssdn/SDN4CoRE/examples/tsnMtd/getnet/HostSwMACTable.txt";
    fs.open(filename.c_str(), ios::out); //write mode

    for (auto x : _HostProfileTable){
        int swix=(x.second).getConnectedSw_topo_index();
        int hostix=(x.second).getTopo_index();
        cTopology::Node * ConnectedSw =_topology.getNode(swix);
        cTopology::Node * Host =_topology.getNode(hostix);

        openflow::Switch_Info tmp = _SwitchInfoTable[ConnectedSw->getModuleId()];
        cTopology::Node * current=ConnectedSw;

        for(int j = 0; j < current->getNumOutLinks();j++){
            if(current->getLinkOut(j)->getRemoteNode()->getModuleId()==Host->getModuleId()){
                //cout<<(x.second).getMacAddress()<<":"<<tmp.getMacAddress()<<":"<<j<<endl;
                fs<<(x.second).getMacAddress()<<":"<<tmp.getMacAddress()<<":"<<j<<endl;
                break;
            }
        }
    }

    fs.close();

}






void OF_Controller::finish(){
    // record statistics
    recordScalar("numPacketIn", numPacketIn);

    std::map<int,int>::iterator iterMap;
    for(iterMap = packetsPerSecond.begin(); iterMap != packetsPerSecond.end(); iterMap++){
        stringstream name;
        name << "packetsPerSecondAt-" << iterMap->first;
        recordScalar(name.str().c_str(),iterMap->second);
    }

    std::map<int,double>::iterator iterMap2;
    for(iterMap2 = avgQueueSize.begin(); iterMap2 != avgQueueSize.end(); iterMap2++){
        stringstream name;
        name << "avgQueueSizeAt-" << iterMap2->first;
        recordScalar(name.str().c_str(),(iterMap2->second/1.0));
    }
}

} /*end namespace openflow*/


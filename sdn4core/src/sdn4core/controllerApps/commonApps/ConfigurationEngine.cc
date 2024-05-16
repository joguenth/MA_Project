///*
// * ConfigurationEngine.cc
// *
// *  Created on: Mar 17, 2021
// *      Author: root
// */
//

#include <sdn4core/controllerApps/commonApps/ConfigurationEngine.h>

using namespace inet;
using namespace CoRE4INET;
using namespace std;
using namespace omnetpp;
using namespace openflow;


namespace SDN4CoRE{
Define_Module(ConfigurationEngine);

ConfigurationEngine::ConfigurationEngine() {
}

ConfigurationEngine::~ConfigurationEngine() {
}

void ConfigurationEngine::initialize() {
    AbstractControllerApp::initialize();
    streamStoreManager = new StreamStore();
    isTaggingEnabled = par("isTaggingEnabled").boolValue();  //false--> all flows are sent with default tag 0
    OF_match_version_number=1;
    numOfPathReconfigurations=0;
}

void ConfigurationEngine::handleParameterChange(const char* parname)
{
    AbstractControllerApp::handleParameterChange(parname);
}

void ConfigurationEngine::receiveSignal(cComponent* src, simsignal_t id, cObject* obj, cObject* details) {
    AbstractControllerApp::receiveSignal(src, id, obj, details);

    if(id==TopologySignalId){
        topo=&(controller->_topology);
        SwitchInfoTable=&(controller->_SwitchInfoTable);
        HostProfileTable=&(controller->_HostProfileTable);
    }
    else if (id == PacketInSignalId) {
        if (OFP_Packet_In *packet_in = dynamic_cast<OFP_Packet_In *>(obj)) {
            if( EthernetIIFrame *frame =  dynamic_cast<EthernetIIFrame *>(packet_in->getEncapsulatedPacket())){
                if (EthernetIIFrameWithQTag* qframe = dynamic_cast< EthernetIIFrameWithQTag*>(frame)){
                    if(string(qframe->getDisplayString()).compare("ACKforFlowMod")==0){
                        //ACK packet coming from the switch that guaranteed that the related match versioned rule is deployed on the switch
                        //cout<<"[ConfigurationEngine::receiveSignal]:ACKforFlowMod"<<endl;
                        uint16_t matchVersion = qframe->getmatchVersion();
                        Switch_Info * swInfo = controller->findSwitchInfoFor(packet_in);
                        vector<int> path = AckWaitingPaths[matchVersion];
                        path.erase(std::remove(path.begin(), path.end(), swInfo->getTopo_index()), path.end());
                        if(path.empty()){//ACK is received all switches on the path
                            //from now on ingress switch will tag frames of this stream with that version number
                            activateMatchVersion(matchVersion);
                            AckWaitingPaths.erase (matchVersion);
                        }
                        else
                            AckWaitingPaths[matchVersion]=path;
                    }

                }
            }
        }

    }
}


void ConfigurationEngine::configureDataPlane(int demandid, uint64_t sid, vector<Assignment> newAssignments){
    cout<<"[ConfigurationEngine::configureDataPlane]:";
    openflow::Stream st;
    uint16_t match_version;

    if(demandid!=-1){ // new demand
        DemandtoStreamIdMap[demandid]=sid; //for every new demand
        st= streamStoreManager->getStreambyId(sid);
    }
    //else demandid==-1 -> redistribution (special value!)

    for (std::vector<Assignment>::iterator it = newAssignments.begin() ; it != newAssignments.end(); ++it){
        int demandId=it->demand_index;
        bool previouslySeen=false;

        for (std::vector<Assignment>::iterator it1 = prevAssignments.begin(); it1 != prevAssignments.end(); ++it1 ){
            if( (it1->demand_index)==demandId){ //previously existing demand
                previouslySeen=true;

                if(it1->path != it->path){  //Reconfiguration

                    it1->path=it->path; //update path in the prevAssignments list
                    numOfPathReconfigurations+=1;

                    openflow::Stream targetStream= streamStoreManager->getStreambyId(DemandtoStreamIdMap[it1->demand_index]);
                    cout<<"[Reconfigured Stream Info:]"<<"Stream id:"<<targetStream.sid<<" with vlan  "<<targetStream.vlanid<<
                            "\t"<<" talker "<<targetStream.talker<< "\t"<<" listener "<<targetStream.listener<<endl;

                    uint16_t match_version;
                    if(!isTaggingEnabled) //default tagging by 0
                        match_version=0;
                    else
                        match_version=OF_match_version_number;

                    AckWaitingPaths[match_version] = it->path;
                    addMatchVersiontoStream(targetStream.sid);

                    //update existing path for this demand
                    insertAssignedPath((it->path), targetStream.vlanid, targetStream.listener, targetStream.talker, match_version);

                    //TODO call GCL config for the mitigated flows as well
                }
                //else --> same path for previous demand
                //do nothing
            }
        }

        if(previouslySeen==false && demandid!=-1){ //new demand, not existed previously
            uint16_t match_version;
            if(!isTaggingEnabled) //default tagging by 0
                match_version=0;
            else
                match_version=OF_match_version_number;

            cout<<"Match version is set to "<<match_version<<" for the new demand id of "<<demandId<<endl;
            AckWaitingPaths[match_version] = it->path;
            addMatchVersiontoStream(sid);

            insertAssignedPath((it->path), st.vlanid, st.listener, st.talker, match_version);

            cout<<"Assigned path between "<<st.talker<<":"<<st.listener<<"vlan="<<st.vlanid<<" for the demand "<<demandId<<" is ";
            for(auto x:(it->path))
                cout<<x<<" ";
            cout<<endl;
            prevAssignments.push_back((*it)); // add new assignment to the records
        }

    }


    //call send  listener ready function when the new rule is sent to all switches
    if(demandid!=-1) //if this is new TT demand
        sendListenerReady(sid, st.vlanid);

}

void ConfigurationEngine::insertAssignedPath(vector<int> path,  uint16_t dl_vlan,  inet::MACAddress dstHost, inet::MACAddress srcHost, uint16_t match_version ){
    std::list<cTopology::Node *> switchesOnPath;

    for(int i=0; i<path.size(); ++i){
        switchesOnPath.push_back(topo->getNode(path[i]));
    }

    cTopology::Node * srcSw= topo->getNode(path[0]);
    int srcSw_ModuleId = srcSw->getModuleId(); //ingress switch for that stream
    IngressSwTable[match_version]= srcSw_ModuleId;


    int srchost_topo_ix,dsthost_topo_ix;
    for (auto x = HostProfileTable->begin(); x != HostProfileTable->end(); x++) {
        if((x->second).getMacAddress()==dstHost.str()){
            dsthost_topo_ix=(x->second).getTopo_index();
        }
        else if((x->second).getMacAddress()==srcHost.str()){
            srchost_topo_ix=(x->second).getTopo_index();
        }
    }

    std::list<cTopology::Node *>  EndtoEndPath= switchesOnPath;
    EndtoEndPath.push_back(topo->getNode(dsthost_topo_ix));
    EndtoEndPath.push_front(topo->getNode(srchost_topo_ix));

    //send to related switch
    TCPSocket * tsocket;
    uint32_t outport=0;

    int inport=0;
    int ix=0;
    int targetSwId=0;
    int nextSwId=0;
    for (auto itr = switchesOnPath.begin(); itr != switchesOnPath.end(); itr++){
        targetSwId=(*itr)->getModuleId();
        tsocket =findRelatedSwitchSocket(targetSwId);
        cTopology::Node * current = *itr;
        cTopology::Node * next;
        cTopology::Node * prev;

        if(ix==0){
            prev= *(EndtoEndPath.begin());
            next= *(std::next(itr,1));
            inport=getInPort(current, prev);
            outport=getOutPort(current, next);
        }
        else if(ix<switchesOnPath.size()-1){ //middle node
            prev= *(std::prev(itr));
            next= *(std::next(itr,1));
            outport=getOutPort(current, next);
            inport=getInPort(current, prev);
        }
        else{ //last switch on the path
            next= *(std::prev(EndtoEndPath.end()));
            prev= *(std::prev(itr));
            outport=getOutPort(current, next);
            inport=getInPort(current, prev);
        }
        ix++;

        openflow::oxm_basic_match match = createDesiredMatch(inport,dstHost,srcHost, dl_vlan,match_version);
        sendFlowModMessage(OFPFC_ADD, match, outport, tsocket,_idleTimeout,_hardTimeout);

    }

}


void ConfigurationEngine::sendListenerReady(uint64_t streamID, uint16_t vlan_identifier ){
    //create ListenerReady msg for relatedTalker
    ListenerReady *listenerReady = new ListenerReady("Listener Ready", inet::IEEE802CTRL_DATA);
    listenerReady->setStreamID(streamID);
    listenerReady->setVlan_identifier(vlan_identifier);

    //inform RequestHandlerControllerApp
    //cout<<"Calling sendListenerReadyToTalker"<<endl;
    cModule *targetModule = getModuleByPath("getnet.open_flow_controller1.controllerApps[0]");
    RequestHandlerControllerApp * requestHandlerModule= check_and_cast<RequestHandlerControllerApp *>(targetModule);
    requestHandlerModule->sendListenerReadyToTalker(listenerReady->dup());
    delete listenerReady;
}

int ConfigurationEngine::getOutPort(cTopology::Node * current, cTopology::Node * next){
    int outport=0;

    //extract outport
    for(int i = 0;i < current->getNumOutLinks();i++){
        if(strstr(current->getLinkOut(i)->getLocalGate()->getName(),"gateCPlane") != NULL)
            continue;

        if(current->getLinkOut(i)->getRemoteNode()->getModuleId()==next->getModuleId()){
            //cout<<"outport "<<i<<endl;
            outport=i;
            break;
        }
    }

    return outport;
}

int ConfigurationEngine::getInPort(cTopology::Node * current, cTopology::Node * prev){

    int inport=0;
    //extract inport
    for(int j = 0; j < current->getNumInLinks();j++){
        if(strstr(current->getLinkIn(j)->getLocalGate()->getName(),"gateCPlane") != NULL)
            continue;

        if(current->getLinkIn(j)->getRemoteNode()->getModuleId()==prev->getModuleId()){
            //cout<<"inport "<<j<<endl;
            inport=j;
            break;
        }
    }
    return inport;
}

TCPSocket * ConfigurationEngine::findRelatedSwitchSocket(int moduleid){
    openflow::Switch_Info tmp = SwitchInfoTable->at(moduleid);
    return tmp.getSocket();
}


oxm_basic_match  ConfigurationEngine::createDesiredMatch(uint16_t inport, MACAddress dst,MACAddress src, uint16_t vlan, uint16_t matchTag) {

    auto builder = OFMatchFactory::getBuilder();
    builder->setField(OFPXMT_OFB_ETH_DST, &dst);
    builder->setField(OFPXMT_OFB_ETH_SRC, &src);
    builder->setField(OFPXMT_OFB_IN_PORT, &inport);
    builder->setField(OFPXMT_OFB_VLAN_VID, &vlan);
    builder->setField(OFPXMT_OFB_TAG, &matchTag);

    oxm_basic_match match = builder->build();
    match.wildcards= 0;


#if OFP_VERSION_IN_USE == OFP_100
    //match.wildcards |= OFPFW_IN_PORT;
    match.wildcards |= OFPFW_DL_TYPE;
    //          match->wildcards |= OFPFW_DL_SRC;
    //          match->wildcards |= OFPFW_DL_DST;
    //match.wildcards |= OFPFW_DL_VLAN;
    match.wildcards |=  OFPFW_DL_VLAN_PCP;
    match.wildcards |= OFPFW_NW_PROTO;
    match.wildcards |= OFPFW_NW_SRC_ALL;
    match.wildcards |= OFPFW_NW_DST_ALL;
    match.wildcards |= OFPFW_TP_SRC;
    match.wildcards |= OFPFW_TP_DST;
    //match.wildcards |= OFPFW_TAG;

#endif

    return match;
}


uint16_t ConfigurationEngine::getMatchVersionbyStreamId(uint64_t sid){
    if(isTaggingEnabled==false) //default tagging by 0
        return 0;

    if (StreamFlowVersionTable.find(sid) != StreamFlowVersionTable.end()){
        versionInfo info = StreamFlowVersionTable[sid];
        if(info.current==0){
            //cout<<"no active version for this stream yet"<<endl;
            return 0;
        }
        else{
            //cout<<"active version for this stream is "<<info.current<<endl;
            return info.current;
        }
    }
    else{ //no record exist for the stream
        //cout<<"no stream record exist"<<endl;
        return 0;

    }
}


void ConfigurationEngine::addMatchVersiontoStream(uint64_t sid){
    if(isTaggingEnabled==false) //default tagging by 0
        return;

    if (StreamFlowVersionTable.find(sid) == StreamFlowVersionTable.end()){ //no stream record exist previously, create a new record for this stream
        versionInfo info = versionInfo();
        info.next=OF_match_version_number;
        OF_match_version_number+=(uint16_t)1;
        StreamFlowVersionTable[sid]=info;
    }
    else{ //previously seen stream, new match version is required to be added
        versionInfo info = StreamFlowVersionTable[sid];
        if(info.next==0){
            info.next=OF_match_version_number;
            OF_match_version_number+=(uint16_t)1;
            StreamFlowVersionTable[sid]=info;

        }
    }

}

void  ConfigurationEngine::activateMatchVersionofStream(uint64_t sid, uint16_t activeVersion){

    if (StreamFlowVersionTable.find(sid) != StreamFlowVersionTable.end()){
        versionInfo info = StreamFlowVersionTable[sid];

        if(info.next==activeVersion){
            info.current=info.next; //activated
            info.next=0;
            StreamFlowVersionTable[sid]=info;
        }
        else{
            cout<<"\tNo version "<<activeVersion<<" is added before "<<endl;
        }

    }
    else{
        cout<<"No such a stream added before "<<sid<<endl;
    }

}

void  ConfigurationEngine::activateMatchVersion(uint16_t activeVersion){

    cout<<"[ConfigurationEngine::activateMatchVersion]";
    uint64_t streamID;
    for (auto i : StreamFlowVersionTable){
        if(i.second.next ==activeVersion){
            versionInfo info = versionInfo();
            info.current=i.second.next; //activated
            info.next=0;
            StreamFlowVersionTable[i.first]=info;
            streamID = i.first;
            cout<<"From now on Stream "<<streamID<<" is going to be tagged with "<<activeVersion<<endl;
            break;
        }
    }


    //tell ingress switch for this stream(with the given match version) to tag packets with that version number (from now on)
    OFP_Packet_Out *packetOut = new OFP_Packet_Out("packetOut");
    packetOut->getHeader().version = OFP_VERSION;
    packetOut->getHeader().type = OFPT_PACKET_OUT;
    packetOut->setBuffer_id(OFP_NO_BUFFER);
    packetOut->setKind(TCP_C_SEND);


    EthernetIIFrameWithQTag * toIngressSwitch = new EthernetIIFrameWithQTag("ActivationMessage");
    toIngressSwitch->setDisplayString("ActivationMessage");
    toIngressSwitch->setmatchVersion(activeVersion);
    toIngressSwitch->setStreamID(streamID);

    packetOut->encapsulate(toIngressSwitch);

    int targetSwId = IngressSwTable[activeVersion];
    TCPSocket * tsocket = findRelatedSwitchSocket(targetSwId);
    tsocket->send(packetOut);
}


void  ConfigurationEngine::printMatchVersionofStreamMap(){
    cout<<"\tStream Id"<<"\t current "<<"\tnext "<<endl;
    for (auto i : StreamFlowVersionTable){
        cout<<"\t"<<i.first<<"\t\t"<<i.second.current<<"\t\t"<<i.second.next<<endl;
    }


}



void ConfigurationEngine::finish(){

    //std::string fid1="ReconfigurationCount";
    //std::string filename1="/root/DynTssdn/SDN4CoRE/examples/tsnMtd/getnet/results/"+fid1+".txt";
    //fs1.open(filename1.c_str(), ios::out | ios::app ); //append mode
    //fs1<<numOfPathReconfigurations<<endl;
    cout<<"Num of reconfigurations:"<<numOfPathReconfigurations<<endl;
    //fs1.close();

    //cout<<"StreamFlowVersionTable"<<endl;
    //printMatchVersionofStreamMap();

    StreamFlowVersionTable.clear();
    AbstractControllerApp::finish();

}

} /*end namespace SDN4CoRE*/




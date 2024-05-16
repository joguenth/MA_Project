/*
 * RequestHandlerControllerApp.cc
 *
 *  Created on: Feb 11, 2021
 *      Author: NSB
 *  SRP implementation for AVB frames, using edge switches + SRP tables at controller and end points
 */

#include <sdn4core/controllerApps/commonApps/RequestHandlerControllerApp.h>
#include <sdn4core/controllerApps/mtd/MTDControllerApp.h>
#include "sdn4core/utility/dynamicmodules/DynamicModuleHandling.h"
#include <sdn4core/controllerApps/shortestpath/ShortestPathControllerApp.h>

using namespace inet;
using namespace CoRE4INET;
using namespace std;
using namespace omnetpp;
using namespace openflow;

namespace SDN4CoRE{

Define_Module(RequestHandlerControllerApp);


RequestHandlerControllerApp::RequestHandlerControllerApp() {
}

RequestHandlerControllerApp::~RequestHandlerControllerApp() {
}

void RequestHandlerControllerApp::initialize() {
    AbstractControllerApp::initialize();
    streamStoreManager = new StreamStore();
}

void RequestHandlerControllerApp::handleParameterChange(const char* parname)
{
    AbstractControllerApp::handleParameterChange(parname);
}

void RequestHandlerControllerApp::receiveSignal(cComponent* src, simsignal_t id,cObject* obj, cObject* details) {
    AbstractControllerApp::receiveSignal(src, id, obj, details);

    if(id==TopologySignalId){
        topo=&(controller->_topology);
        SwitchInfoTable=&(controller->_SwitchInfoTable);
        HostProfileTable=&(controller->_HostProfileTable);
        EdgeSwitches=&(controller->_EdgeSwitches);
    }
    else if (id == PacketInSignalId) {
        cModule *targetModule = getModuleByPath("getnet.open_flow_controller1.controllerApps[2]");
        ShortestPathControllerApp *routingModule = check_and_cast<ShortestPathControllerApp *>(targetModule);
        //MTDControllerApp *routingModule = check_and_cast<MTDControllerApp *>(targetModule);


        if (OFP_Packet_In *packet_in = dynamic_cast<OFP_Packet_In *>(obj)) {
            if (dynamic_cast<CoRE4INET::SRPFrame *>(packet_in->getEncapsulatedPacket())) {
                if (CoRE4INET::SRPFrame * srpFrame = dynamic_cast<CoRE4INET::SRPFrame *>(packet_in->getEncapsulatedPacket())) {
                    if (CoRE4INET::TalkerAdvertise* talkerAdvertise = dynamic_cast<CoRE4INET::TalkerAdvertise*>(srpFrame)) {
                        //save TA, will send listener Ready back later
                        std::cout << "[RequestHandlerControllerApp] received "<<srpFrame->getName()<<" msg" <<endl ;
                        saveTalker(packet_in);
                        routingModule->requestPathforTalker(talkerAdvertise);
                    }}
            }
        }

    }
}


void RequestHandlerControllerApp::saveTalker(OFP_Packet_In* packet_in_msg) {
    Switch_Info * swInfo = controller->findSwitchInfoFor(packet_in_msg);
    int arrivalPort = packet_in_msg->getMatch().OFB_IN_PORT;

    //get SRP Frame
    if (CoRE4INET::SRPFrame * srpFrame = dynamic_cast<CoRE4INET::SRPFrame *>(packet_in_msg->getEncapsulatedPacket())) {
        if (CoRE4INET::TalkerAdvertise* talkerAdvertise = dynamic_cast<CoRE4INET::TalkerAdvertise*>(srpFrame)) {
            openflow::Stream s= Stream();

            s.talker=talkerAdvertise->getSource_address(); // ToDO: remove src address from tha TA msg
            s.talkerInPort=arrivalPort;
            s.talkerSwInfo=swInfo;
            s.vlanid = talkerAdvertise->getVlan_identifier();
            s.sid=talkerAdvertise->getStreamID();
            s.listener=talkerAdvertise->getDestination_address();

            streamStoreManager->addStreamToStore(talkerAdvertise->getStreamID(), s);

            //            cout<<"[RequestHandlerControllerApp::saveTalker]"<<endl;
            //            cout<<"Stream with id of "<<s.sid<<" has been registered "<<
            //                    "\t"<<" inport "<<s.talkerInPort<<
            //                    "\t"<<" talkerSwInfo "<<(s.talkerSwInfo)->getMacAddress()<<
            //                    "\t"<<" talker "<<s.talker<<
            //                    "\t"<<" listener "<<s.listener<<endl;


        }
    }
}


void RequestHandlerControllerApp::sendListenerReadyToTalker(ListenerReady *listenerReady) {
    //forward original to the switch that sends TA initially
    openflow::Stream st= streamStoreManager->getStreambyId(listenerReady->getStreamID());
    forwardSRPPackettoTalker(listenerReady,(st.talkerSwInfo)->getSocket());
}



void RequestHandlerControllerApp::forwardSRPPackettoTalker(ListenerReady *listenerReady, TCPSocket * talkerSwSocket) {
    //TODO use experimenter message instead of packet out!
    OFP_Packet_Out *packetOut = new OFP_Packet_Out("forwardSRP");
    packetOut->getHeader().version = OFP_VERSION;

#if OFP_VERSION_IN_USE == OFP_100
    packetOut->getHeader().type = OFPT_VENDOR;
    // TODO Add Experimenter Message Structure!
#elif OFP_VERSION_IN_USE == OFP_151
    packetOut->getHeader().type = OFPT_EXPERIMENTER;
    // TODO Add Experimenter Message Structure!
#endif
    //packetOut->setBuffer_id(packet_in_msg->getBuffer_id());
    packetOut->setByteLength(24);

    CoRE4INET::SRPFrame* toSwtich = dynamic_cast<CoRE4INET::SRPFrame *>(listenerReady->dup());
    packetOut->encapsulate(toSwtich);

    //packetOut->setIn_port( rq->talkerInPort.OFB_IN_PORT);
    talkerSwSocket->send(packetOut);
    delete listenerReady;
}


void RequestHandlerControllerApp::finish(){
    AbstractControllerApp::finish();
}

} /*end namespace SDN4CoRE*/


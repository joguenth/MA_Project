/*
 * Edge_OF_SwitchAgent.cc
 *
 *  Created on: Apr 22, 2022
 *      Author: root
 */


//SND4CoRE
#include <sdn4core/switch/ieee8021qbv/edgeAgent/Edge_OF_SwitchAgent.h>
//STD
#include <sstream>
#include <string>
//CoRE4INET
#include "core4inet/base/avb/AVBDefs.h"
//AUTO_GENERATED MESSAGES
#include "core4inet/linklayer/ethernet/avb/AVBFrame_m.h"
#include "core4inet/linklayer/ethernet/avb/SRPFrame_m.h"
#include "core4inet/linklayer/contract/ExtendedIeee802Ctrl_m.h"
//openflow
#include "openflow/messages/OFP_Packet_In_m.h"
#include "openflow/messages/OFP_Packet_Out_m.h"
#include "openflow/messages/OFP_Stats_Reply_m.h"


using namespace std;
using namespace inet;
using namespace openflow;
using namespace omnetpp;
using namespace CoRE4INET;
namespace SDN4CoRE{

Define_Module(Edge_OF_SwitchAgent);

#define MSGKIND_STATS                   987

Edge_OF_SwitchAgent::Edge_OF_SwitchAgent() {}
Edge_OF_SwitchAgent::~Edge_OF_SwitchAgent() {}




void Edge_OF_SwitchAgent::initialize(int stage){
    OF_SwitchAgent::initialize(stage);
    isTaggingEnabled = par("isTaggingEnabled").boolValue();

    cMessage *triggerStatSending = new cMessage("triggerStatSending");
    triggerStatSending->setKind(MSGKIND_STATS);
    scheduleAt(3, triggerStatSending);
    //msgSendFlag=false;

    switch(stage){
    case INITSTAGE_LOCAL: {
        //register siganls
        forwardSRPtoConSig = registerSignal("forwardSRPtoConSig");
        relayUnit->subscribe(forwardSRPtoConSig, this);
        break;
    }

    default:

        break;
    }
}


void Edge_OF_SwitchAgent::handleMessage(cMessage *msg){
        OF_SwitchAgent::handleMessage(msg);
}


void Edge_OF_SwitchAgent::processControlPlanePacket(cMessage *msg){
    if (Open_Flow_Message *of_msg = dynamic_cast<Open_Flow_Message *>(msg)) { //msg from controller
        ofp_type type = (ofp_type)of_msg->getHeader().type;
        switch (type){
        // TODO Add Experimenter Message Structure!
#if OFP_VERSION_IN_USE == OFP_100
        case OFPT_VENDOR:
            controlPlanePacket++;
            handleSRPFromController(of_msg);
            break;

#elif OFP_VERSION_IN_USE == OFP_151
        case OFPT_EXPERIMENTER:
            controlPlanePacket++;
            handleSRPFromController(of_msg);
            break;
#endif

        case OFPT_FLOW_MOD:
            if(isTaggingEnabled)
                handleFlowModMessagewithACK(of_msg);
            break;

        case OFPT_PACKET_OUT:
            handlePacketOutMessage(of_msg);
            break;
        default:
            //not a special of message forward to base class.
            OF_SwitchAgent::processControlPlanePacket(msg);
            break;
        }
    }
}


void Edge_OF_SwitchAgent::handleFlowModMessagewithACK(Open_Flow_Message *of_msg){
    //cout << "OF_SwitchAgent::handleFlowModMessagewithACK" << endl;
    if(OFP_Flow_Mod *flowModMsg = dynamic_cast<OFP_Flow_Mod *> (of_msg)){
        _flowTables[flowModMsg->getTable_id()]->handleFlowMod(flowModMsg);

        //reply back to controller as ACK for received flow rule
        oxm_basic_match& match = flowModMsg->getMatch();
        uint16_t matchVersion = match.OFB_TAG;
        EthernetIIFrameWithQTag * toController = new EthernetIIFrameWithQTag("ACKforFlowMod");
        toController->setDisplayString("ACKforFlowMod");
        toController->setmatchVersion(matchVersion);

        OFP_Packet_In *packetIn = new OFP_Packet_In("packetIn");
        packetIn->getHeader().version = OFP_VERSION;
        packetIn->getHeader().type = OFPT_PACKET_IN;
#if OFP_VERSION_IN_USE == OFP_100
        packetIn->setReason(OFPR_NO_MATCH);//TODO maybe add another reason for realtime streams.
#elif OFP_VERSION_IN_USE == OFP_151
        packetIn->setReason(OFPR_ACTION_SET);//TODO maybe add another reason for realtime streams.
#endif
        packetIn->setByteLength(32);

        // allways send full packet with packet-in message
        packetIn->encapsulate(toController);
        packetIn->setBuffer_id(OFP_NO_BUFFER);
        socket.send(packetIn);
        //        IInterfaceTable *inet_ift = getModuleFromPar<IInterfaceTable>(par("interfaceTableModule"), this);
        //        MACAddress mac = inet_ift->getInterface(0)->getMacAddress();
        //        cout<<"at "<<mac<<" ACK for version "<<matchVersion<<" is sent to controller"<<endl;


    }

    delete of_msg;
}
void Edge_OF_SwitchAgent::handleSRPFromController(cMessage* msg) {
    //triggers the relay agent to forward packet comibg from controller to the edge (e.g., talker)
    if (OFP_Packet_Out *packetOut = dynamic_cast<OFP_Packet_Out *>(msg)) {
        if (CoRE4INET::SRPFrame * srpFrame = dynamic_cast<CoRE4INET::SRPFrame *>(packetOut->decapsulate())) {
            if (CoRE4INET::ListenerReady* listenerReady = dynamic_cast<CoRE4INET::ListenerReady*>(srpFrame)) {
                cout<<"--->"<<this->getFullPath()<<" (handleSRPFromController) :ListenerReady taken from the controller "<<std::endl;
                ((Edge_OF_RelayUnit*)relayUnit)->handleSRPMsgFromController(srpFrame);
            }
        }
    }
    delete msg;
}

void Edge_OF_SwitchAgent::receiveSignal(cComponent *src, simsignal_t id, cObject *value, cObject *details){
    if(this->isConnectedToController()){
        if(id == forwardSRPtoConSig){
            Enter_Method_Silent();
            CoRE4INET::SRPFrame* toController = dynamic_cast<CoRE4INET::SRPFrame *>(value);
            forwardSRPtoController(toController);
        }else{
            OF_SwitchAgent::receiveSignal(src, id, value, details);
        }
    }
}


void Edge_OF_SwitchAgent::handlePacketOutMessage(Open_Flow_Message *msg){
    cout << "Edge_OF_SwitchAgent::handlePacketOutMessage" << endl;
    if (OFP_Packet_Out *packetOut = dynamic_cast<OFP_Packet_Out *>(msg)) {
        if (CoRE4INET::EthernetIIFrameWithQTag * qframe = dynamic_cast<CoRE4INET::EthernetIIFrameWithQTag *>(packetOut->decapsulate())) {
            if(string(qframe->getDisplayString()).compare("ActivationMessage")==0) {
                //cout<<"--->"<<this->getFullPath()<<" ActivationMessage taken from the controller "<<std::endl;
                ((Edge_OF_RelayUnit*)relayUnit)->handleMatchVersionMessage(qframe);
            }

        }
    }
    delete msg;
}


void Edge_OF_SwitchAgent::forwardSRPtoController(cPacket* msg) {
    //TODO use experimenter Message for srp forwarding. Maybe add a custom reason.
    OFP_Packet_In *packetIn = new OFP_Packet_In("packetIn");
    packetIn->getHeader().version = OFP_VERSION;
    packetIn->getHeader().type = OFPT_PACKET_IN;
#if OFP_VERSION_IN_USE == OFP_100
    packetIn->setReason(OFPR_NO_MATCH);//TODO maybe add another reason for realtime streams.
#elif OFP_VERSION_IN_USE == OFP_151
    packetIn->setReason(OFPR_ACTION_SET);//TODO maybe add another reason for realtime streams.
#endif
    packetIn->setByteLength(32);
    if (inet::Ieee802Ctrl * controlInfo = dynamic_cast<inet::Ieee802Ctrl *>(msg->getControlInfo())){
        oxm_basic_match match;
        match.OFB_IN_PORT = controlInfo->getSwitchPort();
        packetIn->setMatch(match);
    }

    // allways send full packet with packet-in message
    packetIn->encapsulate(msg->dup());
    packetIn->setBuffer_id(OFP_NO_BUFFER);

    socket.send(packetIn);
    delete msg;
}



} /*end namespace SDN4CoRE*/



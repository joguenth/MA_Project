/*
 * Edge_OF_RelayUnit.cc
 *
 *  Created on: Feb 12, 2021
 *      Author: root
 */

#include "core4inet/linklayer/ethernet/avb/SRPFrame_m.h"
#include "core4inet/linklayer/contract/ExtendedIeee802Ctrl_m.h"
#include "inet/linklayer/ethernet/EtherMACBase.h"
//openflow
#include "openflow/messages/OFP_Packet_In_m.h"
#include "openflow/messages/OFP_Packet_Out_m.h"
#include "sdn4core/switch/tsn/engine/TSN_OF_RelayUnit.h"
#include "core4inet/base/avb/AVBDefs.h"

#include <sdn4core/switch/ieee8021qbv/edgeRelay/Edge_OF_RelayUnit.h>
#include <sdn4core/switch/base/engine/OF_RelayUnit.h>
#include <sstream>
#include <string>

//inet
#include "inet/linklayer/ethernet/EtherMAC.h"
#include "inet/networklayer/ipv4/IPv4Datagram.h"
#include "inet/networklayer/common/L3AddressResolver.h"
#include "inet/transportlayer/contract/ITransportPacket.h"
#include "inet/common/ModuleAccess.h"
#include "inet/networklayer/common/InterfaceTable.h"
#include "inet/networklayer/ipv4/ICMPMessage.h"

#include "core4inet/linklayer/ethernet/base/EtherFrameWithQTag_m.h"

using namespace std;
using namespace inet;
using namespace CoRE4INET;
using namespace openflow;

namespace SDN4CoRE{

Define_Module(Edge_OF_RelayUnit);

void Edge_OF_RelayUnit::initialize(int stage) {

    OF_RelayUnit::initialize(stage);
    forwardSRPtoConSig = registerSignal("forwardSRPtoConSig");
    isTaggingEnabled = par("isTaggingEnabled").boolValue();
}



void Edge_OF_RelayUnit::processDataPlanePacket(cMessage *msg){


    bool msgHandled = false;

    if(msg->arrivedOn("dataPlaneIn")){
        if(inet::EthernetIIFrame * frame = dynamic_cast<inet::EthernetIIFrame *>(msg)) {
            if (dynamic_cast<CoRE4INET::SRPFrame *>(frame->getEncapsulatedPacket())) {
                CoRE4INET::SRPFrame* srpFrame = dynamic_cast<CoRE4INET::SRPFrame *>(frame->decapsulate());
                if (CoRE4INET::TalkerAdvertise* talkerAdvertise = dynamic_cast<CoRE4INET::TalkerAdvertise*>(srpFrame)) {
                    StreamPortMap[talkerAdvertise->getStreamID()]= frame->getArrivalGate()->getIndex();
                    SeenStreams.push_back(talkerAdvertise->getStreamID());

                    inet::Ieee802Ctrl * controlInfo = new inet::Ieee802Ctrl();
                    controlInfo->setSwitchPort(frame->getArrivalGate()->getIndex());
                    controlInfo->setSourceAddress(frame->getSrc()); //this can be used instead of src address field in  TA msg

                    CoRE4INET::SRPFrame* toController = dynamic_cast<CoRE4INET::SRPFrame *>(talkerAdvertise);
                    toController->setControlInfo(controlInfo);
                    emit(forwardSRPtoConSig,toController);
                    cout<<"TA forwarded by  "<<this->getFullPath()<<"to the controller "<<std::endl;
                    msgHandled = true;

                    delete msg; //= frame
                }
            }else if(isTaggingEnabled){
                if (EthernetIIFrameWithQTag* qframe = dynamic_cast< EthernetIIFrameWithQTag*>(frame)){
                    uint64_t sid = qframe->getStreamID();
                    //if I am the ingress point for this frame, rules are already loaded
                    if(std::find(SeenStreams.begin(),   SeenStreams.end(), sid) != SeenStreams.end()){
                        //means that frame is coming from end host that is connected to me
                        uint16_t match_version = StreamActiveMatchVersionMap[sid];
                        qframe->setmatchVersion(match_version);

//                        IInterfaceTable *inet_ift = getModuleFromPar<IInterfaceTable>(par("interfaceTableModule"), this);
//                        MACAddress mac = inet_ift->getInterface(0)->getMacAddress();
//                        cout<<"[Edge_OF_RelayUnit] t:"<<simTime()<<"at "<<mac<<" Stream "<<sid<<"->frame between "<<frame->getSrc()<<":"<<frame->getDest()<<" service type: "<<qframe->getVID()<<" is tagged with "<<match_version<<endl;
                    }
                }
            }
        }

    }

    if(!msgHandled){
        //not handled so forward to base
        OF_RelayUnit::processDataPlanePacket(msg);
    }
}

void Edge_OF_RelayUnit::handleSRPMsgFromController(CoRE4INET::SRPFrame * srpFrame ) {
    Enter_Method("handleSRPMsgFromController");
    //has been triggered by the Edge_OF_Agent
    if (CoRE4INET::ListenerReady* listenerReady = dynamic_cast<CoRE4INET::ListenerReady*>(srpFrame)) {
        std::cout<<"--->"<<this->getFullPath()<<listenerReady->getFullName()<<" msg "<<endl;
        //sent to the realted talker
        uint64_t sid = listenerReady->getStreamID();
        inet::EthernetIIFrame * frame = new inet::EthernetIIFrame(listenerReady->getName());
        frame->setEtherType(MSRP_ETHERTYPE);
        frame->setDest(CoRE4INET::SRP_ADDRESS);
        frame->encapsulate(listenerReady->dup());

        send(frame->dup(), "dataPlaneOut",  StreamPortMap[sid]);
        delete frame;
        delete listenerReady;
    }
}



void Edge_OF_RelayUnit::handleMatchVersionMessage(CoRE4INET::EthernetIIFrameWithQTag * qframe){

    uint16_t activeVersion = qframe->getmatchVersion();
    uint64_t streamId = qframe->getStreamID();

    StreamActiveMatchVersionMap[streamId]=activeVersion;
    // cout<<"New match version is set as "<<activeVersion<<" for sid of "<<streamId<<endl;
    delete qframe;


}

Edge_OF_RelayUnit::~Edge_OF_RelayUnit(){
}


} /*end namespace SDN4CoRE*/

/*
 * IEEE8021QSRPLikeTrafficSourceApp.cc
 *
 *  Created on: Apr 21, 2022
 *      Author: root
 */


#include "core4inet/applications/trafficsource/IEEE8021Q/IEEE8021QSRPLikeTrafficSourceApp.h"

//CoRE4INET
#include "core4inet/base/CoRE4INET_Defs.h"
#include "core4inet/buffer/base/BGBuffer.h"
#include "core4inet/utilities/ConfigFunctions.h"
#include "core4inet/linklayer/ethernet/base/EtherFrameWithQTag_m.h"
#include <iostream>
#include <string>

#define MSGKIND_SEND_TA                 9
#define MSGKIND_STREAMING               10
using namespace std;
namespace CoRE4INET {

Define_Module(IEEE8021QSRPLikeTrafficSourceApp);

IEEE8021QSRPLikeTrafficSourceApp::IEEE8021QSRPLikeTrafficSourceApp()
{
    this->streamID = 0;
    this->isStreaming = false;
}

void IEEE8021QSRPLikeTrafficSourceApp::initialize()
{
    TrafficSourceAppBase::initialize();
    for (unsigned int i = 0; i < this->numPCP; i++)
    {
        simsignal_t signalPk = registerSignal(("txQPcp" + std::to_string(i) + "Pk").c_str());
        cProperty* statisticTemplate = getProperties()->get("statisticTemplate", "txQPcpPk");
        getEnvir()->addResultRecorders(this, signalPk, ("txQPcp" + std::to_string(i) + "Pk").c_str(), statisticTemplate);
        statisticTemplate = getProperties()->get("statisticTemplate", "txQPcpBytes");
        getEnvir()->addResultRecorders(this, signalPk, ("txQPcp" + std::to_string(i) + "Bytes").c_str(), statisticTemplate);

        this->txQPcpPkSignals.push_back(signalPk);
    }

    cMessage *event = new cMessage("TA msg trigger");
    event->setKind(MSGKIND_SEND_TA);
    scheduleAt(this->par( "startTime" ), event);

}

void IEEE8021QSRPLikeTrafficSourceApp::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage())
    {
        if(msg->getKind() == MSGKIND_SEND_TA){
            /*
            cout<<priority<<endl;
            cout<<vid<<endl;
            cout<<streamID<<endl;
            cout<<destAddress<<endl;
            cout<<sendInterval<<endl; //0.01 (s)
            cout<<(sendInterval.str())<<endl;
            string s=sendInterval.str();
            cout<<stof(s)<<endl;
            cout<<this->getPayloadBytes()<<endl;
             */

            sendTAMessage();
        }
        else if(msg->getKind() == MSGKIND_STREAMING  && isStreaming){
            sendMessage();
            scheduleAt(simTime() + this->sendInterval, msg->dup()); //TODO: Use scheduler of the node to support its modeled inaccuracy
        }
    }
    else if (inet::EthernetIIFrame *frame = dynamic_cast<inet::EthernetIIFrame*>(msg)){
        if (CoRE4INET::SRPFrame * srpFrame = dynamic_cast<CoRE4INET::SRPFrame *>(frame->decapsulate())) {
            if (CoRE4INET::ListenerReady* listenerReady = dynamic_cast<CoRE4INET::ListenerReady*>(srpFrame)) {
                if(streamID==listenerReady->getStreamID()){
                    std::cout<<this->getFullPath()<<listenerReady->getFullName()<<" msg received for sid "<<listenerReady->getStreamID()<<std::endl;
                    isStreaming=true;
                    streamStartTime = simTime();
                    cMessage *event = new cMessage("Streaming");
                    event->setKind(MSGKIND_STREAMING);
                    scheduleAt(simTime(), event);
                    delete listenerReady;
                }
            }
        }

    }

    delete msg;

}


void IEEE8021QSRPLikeTrafficSourceApp::sendMessage()
{
    for (std::list<BGBuffer*>::const_iterator buf = bgbuffers.begin(); buf != bgbuffers.end(); ++buf)
    {
        EthernetIIFrameWithQTag *frame = new EthernetIIFrameWithQTag("IEEE 802.1Q Traffic");
        frame->setDest(this->destAddress);
        cPacket *payload_packet = new cPacket();
        payload_packet->setByteLength(static_cast<int64_t>(getPayloadBytes()));
        frame->encapsulate(payload_packet);
        frame->setPcp(priority);
        frame->setVID(this->vid);
        frame->setSchedulingPriority(static_cast<short>(SCHEDULING_PRIORITY_OFFSET_8021Q - priority));
        //Padding
        if (frame->getByteLength() < MIN_ETHERNET_FRAME_BYTES)
        {
            frame->setByteLength(MIN_ETHERNET_FRAME_BYTES);
        }

        frame->setStreamID(streamID);

        emit(this->txQPcpPkSignals[priority], frame);
        sendDirect(frame, (*buf)->gate("in"));
    }

}

void IEEE8021QSRPLikeTrafficSourceApp::sendTAMessage()
{
    for (std::list<BGBuffer*>::const_iterator buf = bgbuffers.begin(); buf != bgbuffers.end(); ++buf)
    {
        TalkerAdvertise *talkerAdvertise = new TalkerAdvertise("Talker Advertise", inet::IEEE802CTRL_DATA);
        talkerAdvertise->setMaxFrameSize(static_cast<uint16_t>(this->getPayloadBytes()));

        string s=sendInterval.str();
        talkerAdvertise->setMaxIntervalFrames(static_cast<uint16_t>(1000*stof(s))); //sending period in second

        talkerAdvertise->setDestination_address(destAddress);
        talkerAdvertise->setVlan_identifier(vid);
        talkerAdvertise->setStreamID(streamID);
        talkerAdvertise->setSource_address(srcAddress);

        EthernetIIFrameWithQTag *frame = new EthernetIIFrameWithQTag("TA msg");
        frame->encapsulate(talkerAdvertise);
        std::cout<<this->getFullPath()<<talkerAdvertise->getFullName()<<" msg for Stream "<<streamID<<endl;
        sendDirect(frame, (*buf)->gate("in"));
    }


}

void IEEE8021QSRPLikeTrafficSourceApp::handleParameterChange(const char* parname)
{
    TrafficSourceAppBase::handleParameterChange(parname);

    if (!parname || !strcmp(parname, "sendInterval"))
    {
        this->sendInterval = parameterDoubleCheckRange(par("sendInterval"), 0, SIMTIME_MAX.dbl());
    }
    if (!parname || !strcmp(parname, "srcAddress"))
    {
        this->srcAddress.setAddress(par("srcAddress").stringValue());
    }
    if (!parname || !strcmp(parname, "destAddress"))
    {
        if (par("destAddress").stdstringValue() == "auto")
        {
            // assign automatic address
            this->destAddress = inet::MACAddress::generateAutoAddress();

            // change module parameter from "auto" to concrete address
            par("destAddress").setStringValue(this->destAddress.str());
        }
        else
        {
            this->destAddress.setAddress(par("destAddress").stringValue());
        }
    }
    if (!parname || !strcmp(parname, "priority"))
    {
        this->priority = static_cast<uint8_t>(parameterLongCheckRange(par("priority"), 0, MAX_Q_PRIORITY));
    }
    if (!parname || !strcmp(parname, "vid"))
    {
        this->vid = static_cast<uint16_t>(parameterLongCheckRange(par("vid"), 0, MAX_VLAN_ID));
    }
    if (!parname || !strcmp(parname, "numPCP"))
    {
        this->numPCP = static_cast<unsigned int>(parameterULongCheckRange(par("numPCP"), 1, std::numeric_limits<int>::max()));
    }
    if (!parname || !strcmp(parname, "streamID"))
    {
#if LONG_BIT == 32
        this->streamID = parameterULongCheckRange(par("streamID"), 0, static_cast<unsigned long>(MAX_STREAM_ID));
#else
        this->streamID = parameterULongCheckRange(par("streamID"), 0, MAX_STREAM_ID);
#endif
    }
}

}
//namespace

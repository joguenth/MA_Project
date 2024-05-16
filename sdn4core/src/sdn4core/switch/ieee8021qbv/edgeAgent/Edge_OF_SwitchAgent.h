/*
 * Edge_OF_SwitchAgent.h
 *
 *  Created on: Apr 22, 2022
 *      Author: root
 */

#ifndef SDN4CORE_SWITCH_IEEE8021QBV_EDGEAGENT_EDGE_OF_SWITCHAGENT_H_
#define SDN4CORE_SWITCH_IEEE8021QBV_EDGEAGENT_EDGE_OF_SWITCHAGENT_H_

//Omneet
#include <omnetpp.h>
//SDN4CoRE
#include <sdn4core/switch/base/engine/OF_SwitchAgent.h>
#include <sdn4core/switch/avb/engine/AVB_OF_RelayUnit.h>
#include <sdn4core/switch/ieee8021qbv/edgeRelay/Edge_OF_RelayUnit.h>
//CoRE4INET
#include "core4inet/services/avb/SRP/SRPTable.h"
#include "core4inet/linklayer/ethernet/base/EtherFrameWithQTag_m.h"


namespace SDN4CoRE{

class Edge_OF_SwitchAgent : public OF_SwitchAgent
{
public:
    Edge_OF_SwitchAgent();
    ~Edge_OF_SwitchAgent();
    virtual void receiveSignal(cComponent *src, simsignal_t id, cObject *value, cObject *details) override;
    virtual void handleMessage(cMessage *msg) override;


protected:
    //omnetpp module funcitons
    virtual void initialize(int stage) override;
    virtual int numInitStages() const override { return inet::NUM_INIT_STAGES; }
    void handlePacketOutMessage(Open_Flow_Message *of_msg);
    bool isTaggingEnabled;
    //bool msgSendFlag;
    void handleFlowModMessagewithACK(openflow::Open_Flow_Message *of_msg);


    /**
     * Processes an OpenFlow packet arriving on controlPlane interface.
     */
    virtual void processControlPlanePacket(omnetpp::cMessage* msg) override;

   /**
     * Handles an SRP message coming from the controller and forwards it to the right modules.
     * @param srp the message to handle
     */
    virtual void handleSRPFromController(omnetpp::cMessage* srp);

    /**
     * Forwards an SRP message to the OpenFlow controller.
     * @param msg srp the message to forward
     */
    virtual void forwardSRPtoController(omnetpp::cPacket* msg);

protected:
    /**
     * used initiate the forwarding of a srpFrame to the Controller using the Edge_OF_SwitchAgent
     */
    simsignal_t forwardSRPtoConSig;

};

} /*end namespace SDN4CoRE*/


#endif /* SDN4CORE_SWITCH_IEEE8021QBV_EDGEAGENT_EDGE_OF_SWITCHAGENT_H_ */

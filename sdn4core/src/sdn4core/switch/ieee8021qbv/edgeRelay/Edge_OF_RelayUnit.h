/*
 * Edge_OF_RelayUnit.h
 *
 *  Created on: Feb 12, 2021
 *      Author: root
 */

#ifndef SDN4CORE_SWITCH_IEEE8021QBV_EDGERELAY_EDGE_OF_RELAYUNIT_H_
#define SDN4CORE_SWITCH_IEEE8021QBV_EDGERELAY_EDGE_OF_RELAYUNIT_H_


#include <omnetpp.h>
#include <sdn4core/switch/base/engine/OF_RelayUnit.h>
#include "core4inet/services/avb/SRP/SRPTable.h"
#include <sdn4core/controllerApps/commonApps/ConfigurationEngine.h>
#include <sdn4core/switch/base/engine/OF_SwitchAgent.h>
#include <vector>
#include <unordered_map>
#include <list>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>     /* system, NULL, EXIT_FAILURE */
#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <memory>
#include <array>
#include <math.h>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <tuple>
#include <sdn4core/switch/ieee8021qbv/edgeAgent/Edge_OF_SwitchAgent.h>

using namespace omnetpp;
namespace SDN4CoRE{


class Edge_OF_RelayUnit : public OF_RelayUnit
{
public:
    void handleSRPMsgFromController(CoRE4INET::SRPFrame * srpFrame );
    void handleMatchVersionMessage(CoRE4INET::EthernetIIFrameWithQTag * qframe);


protected:
    virtual void initialize(int stage) override;
    virtual void processDataPlanePacket(omnetpp::cMessage* msg) override;
    ~Edge_OF_RelayUnit();
    simsignal_t forwardSRPtoConSig;
    bool isTaggingEnabled;


protected:
    std::map<uint64_t, int > StreamPortMap; //streamid-related endhost port
    std::vector<uint64_t> SeenStreams; //strre<ms that I am the ingress switch
    std::map<uint64_t, uint16_t > StreamActiveMatchVersionMap;
};

} /*end namespace SDN4CoRE*/


#endif /* SDN4CORE_SWITCH_IEEE8021QBV_EDGERELAY_EDGE_OF_RELAYUNIT_H_ */

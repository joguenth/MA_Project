/*
 * OPCE2.h
 *
 *  Created on: Oct 9, 2020
 *      Author: root
 */

#ifndef SDN4CORE_CONTROLLERAPPS_OPCE2_OPCE2_H_
#define SDN4CORE_CONTROLLERAPPS_OPCE2_OPCE2_H_


#include <sdn4core/controllerApps/commonApps/ConfigurationEngine.h>
#include "sdn4core/utility/dynamicmodules/DynamicModuleHandling.h"
#include "inet/common/ModuleAccess.h"
#include "inet/linklayer/common/MACAddress.h"
#include "inet/transportlayer/contract/tcp/TCPSocket.h"
//AUTO_GENERATED MESSAGES
#include "inet/transportlayer/contract/tcp/TCPCommand_m.h"

#include "openflow/openflow/controller/Switch_Info.h"

//optimization
#include <Python.h>
#include <time.h>
#include <stdexcept>
#include <iostream>
#include <stdio.h>

//STD
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <iterator>     // std::advance
#include <sstream>
#include <iostream>
#include <queue>
#include <algorithm>
 #include <list>

#include "inet/transportlayer/contract/tcp/TCPSocket.h"

//openflow
#include <openflow/openflow/protocol/OpenFlow.h>
#include "openflow/openflow/controller/Switch_Info.h"
#include "openflow/openflow/controller/Host_Profile.h"
#include "openflow/controllerApps/AbstractControllerApp.h"
#include "openflow/openflow/controller/OF_Controller.h"

#include <omnetpp.h>
#include <sdn4core/controllerApps/commonApps/RequestHandlerControllerApp.h>

#include "openflow/controllerApps/AbstractControllerApp.h"
#include "inet/linklayer/common/MACAddress.h"
#include <stdint.h>

#include "sdn4core/controllerApps/commonApps/Assignment.h"
#include "sdn4core/controllerApps/commonApps/Demand.h"
#include "openflow/openflow/controller/Stream.h"

using namespace omnetpp;
using namespace SDN4CoRE;

//class Node;
namespace SDN4CoRE{

class OPCE2 : public openflow::AbstractControllerApp
{
public:
    OPCE2();
    ~OPCE2();
    int demandIndex;
    int receivedTTDemandCounter; //#of received TT flow requests
    int handledTTDemandCounter; //#of successfully embedded TT flow requests

    virtual void finish() override;
    void requestPathforTalker(CoRE4INET::TalkerAdvertise* talkerAdvertise);

  protected:
    void receiveSignal(omnetpp::cComponent *src, omnetpp::simsignal_t id, omnetpp::cObject *obj, omnetpp::cObject *details) override;
    virtual void initialize();
    virtual void handleParameterChange(const char* parname) override;
    std::vector<Assignment> get_optimal_assignment(std::vector<Demand> ds, std::vector<Assignment> as, int demand_size, int assignment_size);

    cTopology* topo;
    std::unordered_map<int,openflow::Switch_Info>  *SwitchInfoTable;
    std::unordered_map<int,openflow::Host_Profile> *HostProfileTable;
    std::vector<Demand> allDemands;
    std::vector<Assignment> allAssignments;

};

} /*end namespace SDN4CoRE*/

#endif /* SDN4CORE_CONTROLLERAPPS_OPCE2_OPCE2_H_ */

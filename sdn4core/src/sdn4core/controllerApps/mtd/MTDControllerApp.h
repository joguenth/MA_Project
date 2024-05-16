
/*
 * MTDControllerApp.h
 *
 *  Created on: Jul 20, 2023
 *      Author: root
 */



#ifndef SDN4CORE_CONTROLLERAPPS_MachineLearningControllerApp_MTDControllerApp_H_
#define SDN4CORE_CONTROLLERAPPS_MachineLearningControllerApp_MTDControllerApp_H_


#include "sdn4core/controllerApps/utility/SRPTableManagement.h"
#include "sdn4core/controllerApps/utility/MACTableManagement.h"
//STD
#include <vector>
#include <string>
#include <list>
#include <unordered_map>
#include <iterator>     // std::advance
#include <sstream>
#include <iostream>
#include <utility>
#include <sstream>
#include <map>
#include <queue>
#include <algorithm>


//openflow
#include <openflow/openflow/protocol/OpenFlow.h>
#include "openflow/openflow/controller/Switch_Info.h"
#include "openflow/openflow/controller/Host_Profile.h"
#include "openflow/controllerApps/AbstractControllerApp.h"
#include <sdn4core/controllerApps/commonApps/ConfigurationEngine.h>

#include <omnetpp.h>
#include "openflow/controllerApps/AbstractControllerApp.h"
#include "inet/linklayer/common/MACAddress.h"
#include <stdint.h>

using namespace omnetpp;

namespace SDN4CoRE{


class MTDControllerApp :  public openflow::AbstractControllerApp
{
public:
    MTDControllerApp();
    ~MTDControllerApp();
    void requestPathforTalker(CoRE4INET::TalkerAdvertise* talkerAdvertise);

  protected:
    void receiveSignal(omnetpp::cComponent *src, omnetpp::simsignal_t id, omnetpp::cObject *obj, omnetpp::cObject *details) override;
    virtual void initialize();
    virtual void handleParameterChange(const char* parname) override;

    cTopology* topo;
    std::unordered_map<int,openflow::Switch_Info>  *SwitchInfoTable;
    std::unordered_map<int,openflow::Host_Profile> *HostProfileTable;
    std::vector<cTopology::Node *> *EdgeSwitches;

};

} /*end namespace SDN4CoRE*/


#endif /* SDN4CORE_CONTROLLERAPPS_MTDControllerApp_H_ */

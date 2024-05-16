
/*
 * ShortestPathControllerApp.h
 *
 *  Created on: Jul 6, 2020
 *      Author: root
 */



#ifndef SDN4CORE_CONTROLLERAPPS_ShortestPathControllerApp_ShortestPathControllerApp_H_
#define SDN4CORE_CONTROLLERAPPS_ShortestPathControllerApp_ShortestPathControllerApp_H_


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


class ShortestPathControllerApp :  public openflow::AbstractControllerApp
{
public:
    ShortestPathControllerApp();
    ~ShortestPathControllerApp();
    void requestPathforTalker(CoRE4INET::TalkerAdvertise* talkerAdvertise);

  protected:
    void receiveSignal(omnetpp::cComponent *src, omnetpp::simsignal_t id, omnetpp::cObject *obj, omnetpp::cObject *details) override;
    virtual void initialize();
    virtual void handleParameterChange(const char* parname) override;
    int getTopoIndex(int moduleid);

    cTopology* topo;
    std::unordered_map<int,openflow::Switch_Info>  *SwitchInfoTable;
    std::unordered_map<int,openflow::Host_Profile> *HostProfileTable;
    std::vector<cTopology::Node *> *EdgeSwitches;

    //sw-sw path computation
    std::list<cTopology::Node *> getShortestPathFromWeightedGraph(cTopology::Node * src, cTopology::Node * trg);
    bool comparePaths(std::list<cTopology::Node *> p1, std::list<cTopology::Node *> p2);
    std::vector<Assignment> allAssignments;
    int demandId=0;

};

} /*end namespace SDN4CoRE*/


#endif /* SDN4CORE_CONTROLLERAPPS_ShortestPathControllerApp_ShortestPathControllerApp_H_ */

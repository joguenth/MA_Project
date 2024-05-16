///*
// * ConfigurationEngine.h
// *
// *  Created on: Mar 17, 2021
// *      Author: root
// */
//
#ifndef SDN4CORE_CONTROLLERAPPS_COMMONAPPS_CONFIGURATIONENGINE_H_
#define SDN4CORE_CONTROLLERAPPS_COMMONAPPS_CONFIGURATIONENGINE_H_

#include "sdn4core/utility/dynamicmodules/DynamicModuleHandling.h"
#include "inet/common/ModuleAccess.h"
#include "inet/linklayer/common/MACAddress.h"
#include "inet/transportlayer/contract/tcp/TCPSocket.h"
#include "inet/transportlayer/contract/tcp/TCPCommand_m.h"
#include "openflow/openflow/controller/Switch_Info.h"


#include <time.h>
#include <stdexcept>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <iterator>     // std::advance
#include <sstream>
#include <queue>
#include <algorithm>
 #include <list>
#include <stdint.h>

//openflow
#include <openflow/openflow/protocol/OpenFlow.h>
#include "openflow/openflow/controller/Switch_Info.h"
#include "openflow/openflow/controller/Host_Profile.h"
#include "openflow/controllerApps/AbstractControllerApp.h"
#include "openflow/openflow/controller/OF_Controller.h"

#include <omnetpp.h>
#include <sdn4core/controllerApps/commonApps/Assignment.h>
#include <sdn4core/controllerApps/commonApps/RequestHandlerControllerApp.h>
#include <sdn4core/controllerApps/opt/opce2/OPCE2.h>

#include "openflow/openflow/controller/Stream.h"
#include "openflow/openflow/controller/StreamStore.h"


using namespace omnetpp;
using namespace SDN4CoRE;

namespace SDN4CoRE{

//for keeping track of current OF rule version that is valid
struct versionInfo {
    uint16_t next;
    uint16_t current;

    versionInfo() {next = 0; current=0;}
    versionInfo(uint16_t n, uint16_t c) { next=n; current=c;}
};

class ConfigurationEngine : public openflow::AbstractControllerApp
{
public:
    ConfigurationEngine();
    ~ConfigurationEngine();
    virtual void finish() override;
    void configureDataPlane(int demandId, uint64_t sid,std::vector<Assignment> bs );
    void insertAssignedPath(std::vector<int> path, uint16_t dl_vlan,  inet::MACAddress dstHost, inet::MACAddress srcHost,uint16_t matchTag);
    uint16_t getMatchVersionbyStreamId(uint64_t sid);

  protected:
    void receiveSignal(omnetpp::cComponent *src, omnetpp::simsignal_t id, omnetpp::cObject *obj, omnetpp::cObject *details) override;
    virtual void initialize();
    virtual void handleParameterChange(const char* parname) override;
    inet::TCPSocket * findRelatedSwitchSocket(int moduleid);
    openflow::oxm_basic_match  createDesiredMatch( uint16_t inport, inet::MACAddress dst,inet::MACAddress src, uint16_t vlan,uint16_t matchTag) ;
    int getOutPort(cTopology::Node * current, cTopology::Node * next);
    int getInPort(cTopology::Node * current, cTopology::Node * prev);
    void sendListenerReady(uint64_t streamID, uint16_t vlan_identifier );

    cTopology* topo;
    std::unordered_map<int,openflow::Switch_Info>  *SwitchInfoTable;
    std::unordered_map<int,openflow::Host_Profile> *HostProfileTable;
    StreamStore * streamStoreManager;

    int _idleTimeout; // The cached IdleTimeOut parameter.
    int _hardTimeout; //The cached HardTimeOut parameter.

    std::vector<Assignment> prevAssignments;
    int numOfPathReconfigurations;
    std::map<int,uint64_t> DemandtoStreamIdMap;

    //OF rule versioning
    bool isTaggingEnabled;
    uint16_t OF_match_version_number;
    std::map< uint64_t,versionInfo> StreamFlowVersionTable;  //stream id  -> versionInfo
    std::map<uint16_t,vector<int>> AckWaitingPaths;
    std::map<uint16_t,int> IngressSwTable; //map of matchid-ingress switch

    void addMatchVersiontoStream(uint64_t sid);
    void activateMatchVersionofStream(uint64_t sid, uint16_t activeVersion);
    void printMatchVersionofStreamMap();
    void activateMatchVersion(uint16_t activeVersion);
};

}
#endif /* SDN4CORE_CONTROLLERAPPS_COMMONAPPS_CONFIGURATIONENGINE_H_ */

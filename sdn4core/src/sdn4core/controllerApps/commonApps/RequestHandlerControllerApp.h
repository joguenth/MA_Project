/*
 * RequestHandlerControllerApp.h
 *
 *  Created on: Mar 12, 2021
 *      Author: root
 */

#ifndef SDN4CORE_CONTROLLERAPPS_COMMONAPPS_REQUESTHANDLERCONTROLLERAPP_H_
#define SDN4CORE_CONTROLLERAPPS_COMMONAPPS_REQUESTHANDLERCONTROLLERAPP_H_

//openflow
#include <openflow/openflow/protocol/OpenFlow.h>
#include "openflow/openflow/controller/Switch_Info.h"
#include "openflow/controllerApps/AbstractControllerApp.h"
//inet
#include "inet/common/ModuleAccess.h"
#include "inet/linklayer/common/MACAddress.h"
#include "inet/transportlayer/contract/tcp/TCPSocket.h"
//AUTO_GENERATED MESSAGES
#include "inet/transportlayer/contract/tcp/TCPCommand_m.h"
//CoRE4INET
#include "core4inet/base/avb/AVBDefs.h"
//AUTO_GENERATED MESSAGES
#include "core4inet/linklayer/ethernet/avb/AVBFrame_m.h"
#include "core4inet/linklayer/ethernet/avb/SRPFrame_m.h"
#include "core4inet/linklayer/contract/ExtendedIeee802Ctrl_m.h"

#include "openflow/messages/OFP_Flow_Mod_m.h"
#include "openflow/messages/OFP_Packet_In_m.h"
#include "openflow/openflow/controller/OF_Controller.h"
#include "openflow/openflow/protocol/OFMessageFactory.h"
#include "openflow/openflow/protocol/OFMatchFactory.h"
#include "openflow/messages/OFP_Hello_m.h"
#include <core4inet/services/avb/SRP/SRPTable.h>
#include "core4inet/base/CoRE4INET_Defs.h"
#include "core4inet/base/NotifierConsts.h"
#include <sdn4core/controllerApps/opt/opce2/OPCE2.h>

#include "openflow/openflow/controller/Stream.h"
#include "openflow/openflow/controller/StreamStore.h"

namespace SDN4CoRE{


class RequestHandlerControllerApp : public openflow::AbstractControllerApp
{
public:
    RequestHandlerControllerApp();
    ~RequestHandlerControllerApp();
    virtual void finish() override;
    void sendListenerReadyToTalker(CoRE4INET::ListenerReady *listenerReady);

  protected:
    void receiveSignal(omnetpp::cComponent *src, omnetpp::simsignal_t id, omnetpp::cObject *obj, omnetpp::cObject *details) override;
    virtual void initialize();
    virtual void handleParameterChange(const char* parname) override;
    void forwardSRPPackettoTalker(CoRE4INET::ListenerReady *listenerReady,inet::TCPSocket *socket);
    void saveTalker(openflow::OFP_Packet_In* packet_in_msg);

  private:
    cTopology* topo;
    std::unordered_map<int,openflow::Switch_Info>  *SwitchInfoTable;
    std::unordered_map<int,openflow::Host_Profile> *HostProfileTable;
    std::vector<cTopology::Node *> *EdgeSwitches;
    StreamStore * streamStoreManager;
    openflow::Switch_Info *findSwitchInfoForSocket( inet::TCPSocket *socket);
    void sendListenerReady(uint64_t streamID, uint16_t vlan_identifier );
};

} /*end namespace SDN4CoRE*/


#endif /* SDN4CORE_CONTROLLERAPPS_COMMONAPPS_REQUESTHANDLERCONTROLLERAPP_H_ */

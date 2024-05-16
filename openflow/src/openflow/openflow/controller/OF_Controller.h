
#ifndef OF_CONTROLLER_H_
#define OF_CONTROLLER_H_

#include "inet/transportlayer/contract/tcp/TCPSocket.h"
#include "openflow/messages/Open_Flow_Message_m.h"
#include "openflow/messages/OFP_Packet_In_m.h"
#include "openflow/messages/OFP_Hello_m.h"
#include "openflow/openflow/controller/Switch_Info.h"
#include <omnetpp.h>



#include "openflow/openflow/controller/Host_Profile.h"
//STD
#include <vector>
#include <string>
#include <unordered_map>
#include <iterator>     // std::advance
#include <fstream>
#include <string>
#include <queue>
namespace openflow{

class AbstractControllerApp;

class OF_Controller: public cSimpleModule
{
public:
    OF_Controller();
    ~OF_Controller();
    virtual void finish();

    void sendPacketOut(Open_Flow_Message *of_msg, TCPSocket * socket);

    void registerApp(AbstractControllerApp * app);

    TCPSocket *findSocketFor(cMessage *msg) const;
    Switch_Info *findSwitchInfoFor(cMessage *msg) ;
    TCPSocket *findSocketForChassisId(std::string chassisId) const;

    std::vector<Switch_Info >* getSwitchesList() ;
    std::vector<AbstractControllerApp *>* getAppList() ;

    cTopology _topology;
    std::unordered_map<int,openflow::Switch_Info > _SwitchInfoTable;
    std::unordered_map<int,openflow::Host_Profile > _HostProfileTable;
    std::vector<cTopology::Node *>  _EdgeSwitches;

    void extractTopology(const char *NodeType);
    void checkTopology();
    std::vector<int>* getSwitchIndexes();
    std::vector<int>* getHostIndexes();
    void extractSwitchInfoTable();
    void extractHostProfileTable();
    void extractHostSwMacTable();
    int getTopoIndex(int moduleid);
    std::vector<Host_Profile >* getHostsList();


protected:
    /**
     * Observer Signals
     */
    simsignal_t PacketInSignalId;
    simsignal_t PacketOutSignalId;
    simsignal_t PacketHelloSignalId;
    simsignal_t PacketFeatureRequestSignalId;
    simsignal_t PacketFeatureReplySignalId;
    simsignal_t PacketExperimenterSignalId;
    simsignal_t BootedSignalId;
    simsignal_t TopologySignalId;
    simsignal_t PacketStatsReplySignalId;



    /**
     * Statistics
     */
    simsignal_t queueSize;
    simsignal_t waitingTime;
    long numPacketIn;
    std::map<int,int> packetsPerSecond;

    int lastQueueSize;
    double lastChangeTime;
    std::map<int,double> avgQueueSize;

    /**
     * Message Processing
     */
    bool booted = false;
    bool busy;
    double serviceTime;
    std::list<cMessage *> msgList;

    /**
     * Network and Controller State
     */
    std::vector<Switch_Info > switchesList;
    std::vector<AbstractControllerApp *> apps;

    std::vector<int > _switchIndexes; //ned file indexes, TODO
    std::vector<Host_Profile > _hostsList; //need to be filled in host discovery process, TODO
    std::vector<int > _hostIndexes;   //ned file indexes, TODO
    /**

    /**
     * Connection
     */
    TCPSocket socket;

    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    void processQueuedMsg(cMessage *data_msg);
    void calcAvgQueueSize(int size);
    void sendHello(Open_Flow_Message *msg);
    void registerConnection(Open_Flow_Message *msg);
    void sendFeatureRequest(cMessage *msg);
    virtual void handleFeaturesReply(Open_Flow_Message *of_msg);
    virtual void handlePacketIn(Open_Flow_Message *of_msg);
    virtual void handleStatsReply(Open_Flow_Message * of_msg);
    virtual void handleExperimenter(Open_Flow_Message* of_msg);
};

} /*end namespace openflow*/

#endif /* OF_CONTROLLER_H_ */

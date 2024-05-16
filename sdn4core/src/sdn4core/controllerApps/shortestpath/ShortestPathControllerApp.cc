/*
 * ShortestPathControllerApp.cc
 *
 *  Created on: Jul 6, 2020
 *      Author: root
 */

#include <sdn4core/controllerApps/shortestpath/ShortestPathControllerApp.h>
#include "sdn4core/utility/dynamicmodules/DynamicModuleHandling.h"

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
//openflow
#include "openflow/openflow/controller/OF_Controller.h"
#include "openflow/openflow/controller/Switch_Info.h"


using namespace inet;
using namespace CoRE4INET;
using namespace std;
using namespace omnetpp;
using namespace openflow;

namespace SDN4CoRE{

struct compNodeInt {
    bool operator() (const pair<cTopology::Node * ,int> &a, const pair<cTopology::Node * ,int> &b) {
        return a.second > b.second;
    }
};

Define_Module(ShortestPathControllerApp);

ShortestPathControllerApp::ShortestPathControllerApp() {

}

ShortestPathControllerApp::~ShortestPathControllerApp() {
}

void ShortestPathControllerApp::initialize() {
    //register signals
    AbstractControllerApp::initialize();

}


void ShortestPathControllerApp::handleParameterChange(const char* parname)
{
    AbstractControllerApp::handleParameterChange(parname);
}


void ShortestPathControllerApp::receiveSignal(cComponent* src, simsignal_t id, cObject* obj, cObject* details) {
    AbstractControllerApp::receiveSignal(src, id, obj, details);
    if(id==TopologySignalId){
        topo=&(controller->_topology);
        SwitchInfoTable=&(controller->_SwitchInfoTable);
        HostProfileTable=&(controller->_HostProfileTable);
        EdgeSwitches=&(controller->_EdgeSwitches);
    }
}


std::list<cTopology::Node *> ShortestPathControllerApp::getShortestPathFromWeightedGraph(cTopology::Node * dst, cTopology::Node * src){
    std::list<cTopology::Node * > result = std::list<cTopology::Node *>();
    std::map<cTopology::Node *,bool> visited = std::map<cTopology::Node *,bool>();
    std::map<cTopology::Node *,int> dist = std::map<cTopology::Node *,int>();
    std::map<cTopology::Node *, cTopology::Node *> prev = std::map<cTopology::Node *, cTopology::Node *>();

    priority_queue< pair<cTopology::Node* , int> , vector<pair<cTopology::Node* , int>>, compNodeInt > q;

    //init verticies
    for(int i = 0; i< topo->getNumNodes(); i++){
        cTopology::Node * tmpNode = topo->getNode(i);
        string sh=tmpNode->getModule()->getFullName();
        if(tmpNode == dst){
            continue;
        }

        if(sh.find("switch")!=std::string::npos){  //if node is switch
            q.push(pair<cTopology::Node *,int>(tmpNode, std::numeric_limits<int>::max()));
            dist[tmpNode] = std::numeric_limits<int>::max();
            prev[tmpNode] = NULL;
        }
    }

    //init dst
    q.push(pair<cTopology::Node *,int>(dst, 0));
    dist[dst] = 0;
    prev[dst] = NULL;

    cTopology::Node * u = NULL;
    while(!q.empty()){

        u = q.top().first;
        q.pop();

        if(visited.count(u)>0){
            continue;
        }

        int alt;

        for(int i = 0;i < u->getNumOutLinks();i++){
            //ignore control plane
            if(strstr(u->getLinkOut(i)->getLocalGate()->getName(),"gateCPlane") != NULL){
                continue;
            }

            if(visited.count(u->getLinkOut(i)->getRemoteNode())<=0){
                //alt = dist[u]+1;
                alt = dist[u]+u->getLinkOut(i)->getWeight();
                if(alt < dist[u->getLinkOut(i)->getRemoteNode()]){
                    dist[u->getLinkOut(i)->getRemoteNode()] = alt;
                    prev[u->getLinkOut(i)->getRemoteNode()]=u;
                    q.push(pair<cTopology::Node *,int>(u->getLinkOut(i)->getRemoteNode(),alt));
                }
            }
        }

        visited[u] = true;
    }

    cTopology::Node * tempsrc = src;
    while(prev[tempsrc] != NULL){
        result.push_back(tempsrc);
        tempsrc = prev[tempsrc];
    }
    result.push_back(tempsrc);

    if(tempsrc != dst){
        result.clear();
    }

    return result;
}


int ShortestPathControllerApp::getTopoIndex(int moduleid) {
    for(int i=0;i<topo->getNumNodes();i++){
        if(moduleid==topo->getNode(i)->getModuleId()){
            return i;
        }
    }
    return -1;
}


void ShortestPathControllerApp::requestPathforTalker(CoRE4INET::TalkerAdvertise* talkerAdvertise){
    int srcSw,dstSw=0;
    inet::MACAddress srcHost= talkerAdvertise->getSource_address();
    inet::MACAddress dstHost=talkerAdvertise->getDestination_address();
    uint16_t vlan=talkerAdvertise->getVlan_identifier();

    cout<<"[ShortestPathControllerApp::requestPathforTalker()]"<<endl;
    cout<<"Stream with id of "<<talkerAdvertise->getStreamID()<<
            "\t"<<" from "<<srcHost<<"\t"<<" to "<<dstHost<<
            "\t"<<" with period of "<<talkerAdvertise->getMaxIntervalFrames()<<
            "\t"<<" MaxFrameSize of"<<talkerAdvertise->getMaxFrameSize()<<endl;

    for (auto x = HostProfileTable->begin(); x != HostProfileTable->end(); x++) {
        if((x->second).getMacAddress()==srcHost.str()){
            srcSw=(x->second).getConnectedSw_topo_index();
        }
        else if((x->second).getMacAddress()==dstHost.str()){
            dstSw=(x->second).getConnectedSw_topo_index();
        }
    }

    std::list<cTopology::Node *> tmpPath=getShortestPathFromWeightedGraph( topo->getNode(dstSw),topo->getNode(srcSw));

    Assignment as = Assignment();
    as.demand_index=demandId;
    demandId+=1;

    float rate=(float(8)*talkerAdvertise->getMaxFrameSize())/ (talkerAdvertise->getMaxIntervalFrames()*pow(10,3)); //Mbps
    as.data=rate;

    std::vector<int> path;
    for(auto x:tmpPath){
        path.push_back(getTopoIndex(x->getModuleId()));
    }

    cout<<"Inserted path is ";
    for(auto x:path){
        cout<<x<<"\t";
    }
    cout<<endl;

    as.path=path;

    //as.path_index = 0;
    allAssignments.push_back(as);

    cModule *targetModule = getModuleByPath("getnet.open_flow_controller1.controllerApps[1]");
    ConfigurationEngine * confEngine = check_and_cast<ConfigurationEngine *>(targetModule);
    confEngine->configureDataPlane(as.demand_index,talkerAdvertise->getStreamID(),allAssignments);

}


bool ShortestPathControllerApp::comparePaths(list<cTopology::Node *> p1, list<cTopology::Node *> p2){
    if(p1.size()!=p2.size())
        return false;

    list<cTopology::Node *>::iterator  it1,it2;

    for  ( it1 = p1.begin(), it2 = p2.begin(); it1 != p1.end() && it2 != p2.end(); ++it1, ++it2) {
        if((*it1)->getModuleId()!=(*it2)->getModuleId())
            return false;
    }
    return true;
}

} /*end namespace SDN4CoRE*/




/*
 * MTDControllerApp.cc
 *
 *  Created on: Jul 20, 2023
 *      Author: root
 */

#include <sdn4core/controllerApps/mtd/MTDControllerApp.h>
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
#include "openflow/messages/OFP_Stats_Reply_m.h"


using namespace inet;
using namespace CoRE4INET;
using namespace std;
using namespace omnetpp;
using namespace openflow;

namespace SDN4CoRE{
Define_Module(MTDControllerApp);

MTDControllerApp::MTDControllerApp() {

}

MTDControllerApp::~MTDControllerApp() {
}

void MTDControllerApp::initialize() {
    //register signals
    AbstractControllerApp::initialize();

}


void MTDControllerApp::handleParameterChange(const char* parname)
{
    AbstractControllerApp::handleParameterChange(parname);
}



void MTDControllerApp::receiveSignal(cComponent* src, simsignal_t id, cObject* obj, cObject* details) {
    AbstractControllerApp::receiveSignal(src, id, obj, details);
    if(id==TopologySignalId){
        topo=&(controller->_topology);
        SwitchInfoTable=&(controller->_SwitchInfoTable);
        HostProfileTable=&(controller->_HostProfileTable);
        EdgeSwitches=&(controller->_EdgeSwitches);
    }
}



/*
 * The calculateCandidatePaths(topology topo, string rule) function calculates and stores possible paths for each src dst pair in
 * the topology. std::map<pair<cTopology::Node *,cTopology::Node *>,std::list<std::list<cTopology::Node *>>> pathsForSrcDstPairs
 * PSEUDO:
 * void MTDControllerAPP::calculateCandidatePaths(topology topo, int numPaths){
 * std::list<cTopology::Node *> candidatePath;// tmp path variable
 * std::list<std::list<cTopology::Node *>> listOfCandidatePaths;// tmp list of paths variable
 * for(int i=0;i<topo.getNumNodes();i++){//iterate over topology
 * cTopology::Node * tmpNode1 = topo->getNode(i);
 * for(int j=0;j<topo.getNumNodes();j++){
 * cTopology::Node * tmpNode2 = topo->getNode(j);
 * if(tmpNode1 == tmpNode2) continue;//exclude src==dst
 * YEN_ALG(topo, tmpNode1, tmpNode2, numPaths){
 * ...
 * candidatePath = YEN_ALG_STEP;
 * listOfCandidatePaths.push(candidatePath);
 * ...
 * }
 * pathsForSrcDstPairs[std::make_pair(src,dst)] = listOfCandidatePaths;
 * }
 * }
 * }
 */

/*
 * The getCandidatePaths(src, dst) function returns a list of paths for a given pair of src and dst.
 * It retrieves the list from a common data structure (perhaps a map),
 * e.g. "map<pair<cTopology::Node *,cTopology::Node *>,std::list<std::list<cTopology::Node *>>>" pathsForSrcDstPairs
 * PSEUDO:
 * std::list<std::list<cTopology::Node *>> MTDControlerApp::getCandidatePaths(cTopology::Node * src, cTopology::Node * dst){
 * std::list<std::list<cTopology::Node *>> result = pathsForSrcDestPairs[std::make_pair(src,dst)];// this enough? Otherwise see below
 * for(int i=0;i<topo.getNumNodes();i++){
 * cTopology::Node * tmpNode1 = topo->getNode(i);
 * for(int j=0;j<topo.getNumNodes();j++){
 * cTopology::Node * tmpNode2 = topo->getNode(j);
 * if(tmpNode1 == src && tmpNode2 == dst){
 * result = pathsForSrcDstPairs[make_pair(tmpNode1,tmpNode2)];
 * }
 * }
 * }
 * return result;
 * }// If this doesnt work, because pair<node,node> doesnt work properly in map, the for loop will extract the topology indices and the map
 *      will store by map<pair<int, int>, list>
 */

/*
 * The choosePath(list, rule) function returns a path, which is chosen from list according to the rule.
 * This is done in a case switch according to the rule, which is a string with several configuration options.
 * Those options are: random, fulldisjunct, nextbest
 * std::list<cTopology::Node *> MTD::choosePath(std::list<std::list<cTopology::Node *>> listOfPaths, string rule){
 * int index, sizeOfList = listOfPaths.length;
 * std::list<cTopology::Node *> result;
 * switch(str2int(rule)){
 * case str2int("random"):
 * index = (int)rnd(0,1)*sizeOfList;
 * result = list[index];
 * break;
 * case str2int("nextbest"):
 * for(int i=0; i<sizeOfList; i++){
 * if(ShortestPathControllerApp::comparePaths(list[i], currentPath)){
 * index = i+1;
 * break;
 * }
 * }
 * result = list[index];
 * break;
 * \\... other rule cases. Probably not necessary for thesis but interesting for further investigation of mutation modes
 * }
 * }
 */

/*
 * The getNextPathFromWeightedGraph(src, dst) function returns a path between given src and dst nodes, for example
 * by choosing randomly, or by a defined distance metric between paths etc.
 * PSEUDO:
 * std::list<cTopology::Node *> MTDControllerApp::getNextPathFromWeightedGraph(cTopology::Node * src, cTopology::Node * dst, string rule){
 * std::list<cTopology::Node *> result = std::list<cTopology::Node *>();
 * std::list<std::list<cTopology::Node *>> listOfPossiblePaths = getCandidatePaths(src, dst);
 * result = choosePath(listOfPossiblePaths, rule);
 * if(result.begin !=src || result.end !=dst){
 * result.clear;
 * }
 * return result;
 * }
 */

void MTDControllerApp::requestPathforTalker(CoRE4INET::TalkerAdvertise* talkerAdvertise){
     // TO-DO
    /*
     * periodically generate new paths for each talker in accordance with rules,
     * such as fully/partially disjunct paths, at what point repetitions are allowed etc.
     * Store connections and their respective paths in a map<pair<src,dst>,list<cTopology::Node *>>
     * does this need to be connection specific (ports/TCP connection) or pair<sr,dst> sufficient?
     * Initially invoke ShortestPathControllerApp::getShortestPathFromWeightedGraph(cTopology::Node * dst, cTopology::Node * src),
     * and for each consecutive new path MTDControllerApp::getNextPathFromWeightedGraph(cTopology::Node * dst, cTopology::Node * src).
     *
     * See above, but calculate a set of paths with the same functions in advance, OF controller stores them and periodically changes the path in use,
     * according to a rule (random, "next best", disjunctiveness, etc) and also incorporate a CD for each path before re-used.
     *
     * start with shortest, keep current path in a state variable currentPath
     */

    /*
     * PSEUDO:
     * std::list<cTopology::Node *> newPathTmp = getNextPathFromWeightedGraph(src, dst);
     * */
}

}
/*end namespace SDN4CoRE*/




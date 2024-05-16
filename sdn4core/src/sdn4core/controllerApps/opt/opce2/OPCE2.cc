/*
 * OPCE2.cc
 *
 *  Created on: Oct 9, 2020
 *      Author: root
 */


#include <sdn4core/controllerApps/opt/opce2/OPCE2.h>
using namespace inet;
using namespace CoRE4INET;
using namespace std;
using namespace omnetpp;
using namespace openflow;

namespace SDN4CoRE{
Define_Module(OPCE2);

OPCE2::OPCE2() {

}

OPCE2::~OPCE2() {
}

void OPCE2::initialize() {
    demandIndex=0;
    receivedTTDemandCounter = 0;
    handledTTDemandCounter = 0;

    AbstractControllerApp::initialize();

    if(!Py_IsInitialized()){
        Py_Initialize();
        PyRun_SimpleString("import sys");
        PyRun_SimpleString("import os");
        PyObject *sysPath = PySys_GetObject((char*)"path");
        PyList_Append(sysPath, PyString_FromString("/root/DynTssdn/SDN4CoRE/src/sdn4core/controllerApps/opt/opce2/"));
    }
}

void OPCE2::handleParameterChange(const char* parname)
{
    AbstractControllerApp::handleParameterChange(parname);
}





vector<Assignment> OPCE2::get_optimal_assignment(vector<Demand> ds, vector<Assignment> as, int demand_size, int assignment_size) {
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append(\".\")");

    PyObject *pName, *pModule, *pDict, *pFunc, *pArgs, *pList, *pList_assignments;

    pName = PyString_FromString("main");  // script name
    pModule = PyImport_Import(pName);       // loaded script

    //PyErr_PrintEx(1);  // debug

    if(pModule == NULL)
        throw std::invalid_argument("Script cannot be loaded.\n");

    pDict = PyModule_GetDict(pModule);
    pFunc = PyDict_GetItemString(pDict, "optimize"); // load function

    pList = PyList_New(demand_size);

    pList_assignments = PyList_New(assignment_size);

    for(unsigned int i = 0; i < demand_size; i++) {
        Demand d = ds[i];
        PyObject *pd = Py_BuildValue("(iiiiff)", d.index, d.talker, d.listener, d.service_type, d.max_data, d.max_latency);
        PyList_SetItem(pList, i, pd);
    }

    for(unsigned int i = 0; i < assignment_size; i++) {
        Assignment a = as[i];
        PyObject *pd = Py_BuildValue("(ii)", a.demand_index, a.path_index);
        PyList_SetItem(pList_assignments, i, pd);
    }

    pArgs = Py_BuildValue("(SS)", pList, pList_assignments);    // load arguments

    PyObject* pResult = PyObject_CallObject(pFunc, pArgs); // call function

    //PyErr_PrintEx(1);  // debug

    if(pResult == NULL)
        return {};
    //throw std::invalid_argument("Method call failed.\n");

    // parse output coming from optimization problem

    vector<Assignment> path_assignments;

    if(PyList_Check(pResult)) {
        int size_assignment = int(PyList_Size(pResult));

        for(unsigned int i = 0; i < size_assignment; i++) {
            PyObject *item = PyList_GetItem(pResult, i);

            int index = PyInt_AsLong(PyTuple_GetItem(item, 0));
            float data = PyFloat_AsDouble(PyTuple_GetItem(item, 1));

            PyObject *path = PyTuple_GetItem(item, 2);

            int path_index = PyInt_AsLong(PyTuple_GetItem(item, 3));

            int path_length = int(PyList_Size(path));

            vector<int> cpath;

            for(unsigned int j = 0; j < path_length; j++) {
                cpath.push_back(PyInt_AsLong(PyList_GetItem(path, j)));
            }

            Assignment as = Assignment();
            as.demand_index=index;
            as.data=data;
            as.path=cpath;
            as.path_index =path_index;

            path_assignments.push_back(as);
        }
    }
    return path_assignments;

}



void OPCE2::receiveSignal(cComponent* src, simsignal_t id, cObject* obj, cObject* details) {
    AbstractControllerApp::receiveSignal(src, id, obj, details);
    if(id==TopologySignalId){
        topo=&(controller->_topology);
        SwitchInfoTable=&(controller->_SwitchInfoTable);
        HostProfileTable=&(controller->_HostProfileTable);
    }
}

void OPCE2::requestPathforTalker(CoRE4INET::TalkerAdvertise* talkerAdvertise){
    int id=demandIndex;
    demandIndex+=1;
    receivedTTDemandCounter+=1;
    cout<<"New TT demand added with ix of "<<id<<endl;

    StreamStore ss;
    Stream st = ss.getStreambyId(talkerAdvertise->getStreamID());
    Switch_Info *swInfo = st.talkerSwInfo;

    int src_topo_index,dst_topo_index,dst_host_topo_index;
    inet::MACAddress srcSwitch =MACAddress(swInfo->getMacAddress().c_str());
    src_topo_index=swInfo->getTopo_index();

    cout<<"[OPCE2::requestPathforTalker()]"<<endl;
    cout<<"Stream with id of "<<st.sid<<" has read from Stream Store "<<
            "\t"<<" inport "<<st.talkerInPort<<
            "\t"<<" talkerSwInfo "<<(st.talkerSwInfo)->getMacAddress()<<
            "\t"<<" talker "<<st.talker<<
            "\t"<<" listener "<<st.listener<<
            "\t"<<" period "<<talkerAdvertise->getMaxIntervalFrames()<<
            "\t"<<" MaxFrameSize "<<talkerAdvertise->getMaxFrameSize()<<endl;

    std::unordered_map<int,openflow::Host_Profile>::iterator it1;
    for (it1 = HostProfileTable->begin(); it1 != HostProfileTable->end(); ++it1 ){
        if(MACAddress((it1->second).getMacAddress().c_str())==talkerAdvertise->getDestination_address()){
            dst_topo_index= it1->second.getConnectedSw_topo_index();
            break;
        }
    }

    float rate=(float(8)*talkerAdvertise->getMaxFrameSize())/ (talkerAdvertise->getMaxIntervalFrames()*pow(10,3)); //Mbps

    //call optimization for a dedicated path
    if(src_topo_index!=dst_topo_index){
        Demand d= Demand( id, src_topo_index, dst_topo_index,talkerAdvertise->getVlan_identifier(),rate, float(7));
        allDemands.push_back(d);

        //call opt problem
        vector<Assignment> returnedAssignments = get_optimal_assignment(allDemands, allAssignments, allDemands.size(), allAssignments.size());

        if(!returnedAssignments.empty()) {
            cout<<allDemands.size()<<" demand and "<<allAssignments.size()<<" assignments sent to optimization, "<<returnedAssignments.size()<<" assignments returned "<<endl;
            allAssignments=returnedAssignments;

            //inform ConfigurationEngine
            cout<<"Calling ConfigurationEngine"<<endl;
            cModule *targetModule = getModuleByPath("getnet.open_flow_controller1.controllerApps[1]");
            ConfigurationEngine * confEngine = check_and_cast<ConfigurationEngine *>(targetModule);
            confEngine->configureDataPlane(id,talkerAdvertise->getStreamID(),allAssignments);

        }
        else{  //assignments return empty, cannot embed that flow via opce2
            allDemands.pop_back();
            demandIndex-=1;
        }

    }
}


void OPCE2::finish(){

    Py_Finalize();
    std::ofstream fs;
    for (std::vector<Demand>::iterator it = allDemands.begin() ; it != allDemands.end(); ++it)
        handledTTDemandCounter++;

    std::string fid="EmbeddingRate";
    std::string filename="/root/DynTssdn/SDN4CoRE/examples/tsnMtd/getnet/results/"+fid+".txt";
    fs.open(filename.c_str(), ios::out | ios::app ); //append mode
    fs<<handledTTDemandCounter<<":"<< receivedTTDemandCounter<<":"<< (1.0*handledTTDemandCounter/receivedTTDemandCounter)<<endl;
    cout<<handledTTDemandCounter<<" is embedded out of "<< receivedTTDemandCounter<<" TT flows:"<< (1.0*handledTTDemandCounter/receivedTTDemandCounter)<<endl;
    fs.close();

    //cleaning
    allDemands.clear();
    allAssignments.clear();
    AbstractControllerApp::finish();
    }

} /*end namespace SDN4CoRE*/






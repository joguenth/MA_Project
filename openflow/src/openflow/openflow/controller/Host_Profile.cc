/*
 * Host_Profile.cc
 *
 *  Created on: Jul 19, 2020
 *      Author: root
 */


#include <omnetpp.h>
#include "openflow/openflow/controller/Host_Profile.h"

using namespace std;
using namespace inet;

namespace openflow{

Host_Profile::Host_Profile(){

}

string Host_Profile::getMacAddress() const {
        return macAddress;
}

void Host_Profile::setMacAddress(string macAddress) {
        this->macAddress = macAddress;
}

int Host_Profile::getConnectedSw_topo_index() const{
        return connectedSw_topo_index;
};
void Host_Profile::setConnectedSw_topo_index(int t){
    this->connectedSw_topo_index=t;
};

int Host_Profile::getTopo_index() const{
    return this->topoindex;
};

void Host_Profile::setTopo_index(int t){
    this->topoindex=t;
};



} /*end namespace ofp*/



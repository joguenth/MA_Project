/*
 * Assignment.cc
 *
 *  Created on: Mar 28, 2021
 *      Author: Nurefsan Sertbas Bulbul
 */


#include <omnetpp.h>
#include "sdn4core/controllerApps/commonApps/Assignment.h"

using namespace std;

namespace SDN4CoRE{

Assignment::Assignment(){
    demand_index = -1;
    data = 0.0;
    path_index = -1;

};

Assignment::Assignment(int i, float d, vector<int> p, int j) {
    demand_index = i;
    data = d;
    path = p;
    path_index = j;
}

Assignment& Assignment::operator=(const Assignment& a) {
    demand_index = a.demand_index;
    data = a.data;
    path = a.path;
    path_index = a.path_index;
    return *this;
}

Assignment::Assignment(const Assignment &a) {
    demand_index = a.demand_index;
    data = a.data;
    path = a.path;
    path_index = a.path_index;
}

bool Assignment::operator==(const Assignment& a) {
    if((a.demand_index == demand_index) &&  (a.data == data) && (a.path == path))
        return true;
    else
        return false;
}


} /*end namespace SDN4CoRE*/








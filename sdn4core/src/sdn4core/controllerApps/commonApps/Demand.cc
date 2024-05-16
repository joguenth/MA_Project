/*
 * Demand.cc
 *
 *  Created on: Mar 28, 2021
 *      Author: root
 */


#include <omnetpp.h>
#include "sdn4core/controllerApps/commonApps/Demand.h"

using namespace std;

namespace SDN4CoRE{


Demand::Demand() {
        index = -1;
        talker = 0;
        listener = 0;
        service_type = 0;
        max_data = 0.0;
        max_latency = 0.0;
    }


Demand::Demand(int i, int t, int l, int s, float d, float lt) {
        index = i;
        talker = t;
        listener = l;
        service_type = s;
        max_data = d;
        max_latency = lt;
    }

Demand::Demand(const Demand &d) {
        index = d.index;
        talker = d.talker;
        listener = d.listener;
        service_type = d.service_type;
        max_data = d.max_data;
        max_latency = d.max_latency;
    }

Demand& Demand::operator=(const Demand& d) {
    index = d.index;
    talker = d.talker;
    listener = d.listener;
    service_type = d.service_type;
    max_data = d.max_data;
    max_latency = d.max_latency;
    return *this;
}



bool Demand::operator==(const Demand& d) {
        if( (talker == d.talker) && (listener == d.listener) && (service_type == d.service_type) && (max_data == d.max_data) )
            return true;
        else
            return false;

    }



} /*end namespace SDN4CoRE*/



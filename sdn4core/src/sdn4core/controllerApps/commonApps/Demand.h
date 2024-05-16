/*
 * Demand.h
 *
 *  Created on: Mar 28, 2021
 *      Author: root
 */

#ifndef SDN4CORE_CONTROLLERAPPS_COMMONAPPS_DEMAND_H_
#define SDN4CORE_CONTROLLERAPPS_COMMONAPPS_DEMAND_H_

using namespace std;
#include <stdexcept>
#include <vector>
#include <stdio.h>

namespace SDN4CoRE{


class Demand {
public:
    int index;

        int talker;
        int listener;

        int service_type; // 0-7 service priority class

        float max_data; // maximum data rate to reserve links
        float max_latency; // maximum tolerable latency

        Demand();
        Demand(int i, int t, int l, int s, float d, float lt);
        Demand(const Demand &d) ;
        Demand& operator=(const Demand& d);
        bool operator==(const Demand& d) ;


};

}

#endif /* SDN4CORE_CONTROLLERAPPS_COMMONAPPS_DEMAND_H_ */

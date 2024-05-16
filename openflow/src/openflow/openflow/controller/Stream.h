/*
 * Stream.h
 *
 *  Created on: Sep 21, 2020
 *      Author: root
 */

#ifndef CORE4INET_UTILITIES_STREAM_H_
#define CORE4INET_UTILITIES_STREAM_H_

//inet
#include "inet/common/ModuleAccess.h"
#include "inet/linklayer/common/MACAddress.h"
#include "inet/transportlayer/contract/tcp/TCPSocket.h"
#include "inet/transportlayer/contract/tcp/TCPCommand_m.h"
#include "openflow/openflow/controller/Switch_Info.h"

#include <iostream>
#include <list>
#include <map>
#include <utility>      // std::pair, std::make_pair
#include <unordered_map>
#include <omnetpp.h>
#include <iterator>


using namespace std;
using namespace inet;
namespace openflow{

class Stream {
    public:
        Stream();
        ~Stream();
        Stream(const Stream &other);
        uint64_t sid;
        uint16_t vlanid;
        int talkerInPort;
        float sendingPeriod; //e.g., 2.3 (ms)
        float rate;
        openflow::Switch_Info*  talkerSwInfo;
        inet::MACAddress talker;
        inet::MACAddress listener;
        std::vector<int> assignedPath;
        int pathIndex;
};

}
#endif /* CORE4INET_UTILITIES_STREAM_H_ */

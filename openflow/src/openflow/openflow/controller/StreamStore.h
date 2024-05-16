/*
 * StreamStore.h
 *
 *  Created on: Mar 17, 2021
 *      Author: root
 */

#ifndef OPENFLOW_OPENFLOW_CONTROLLER_STREAMSTORE_H_
#define OPENFLOW_OPENFLOW_CONTROLLER_STREAMSTORE_H_

#include <iostream>
#include <omnetpp.h>
#include <map>
#include "openflow/openflow/controller/Stream.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;
using namespace openflow;

extern std::map<uint64_t, Stream> RegisteredStreams;

class StreamStore {

public:
    StreamStore();
    virtual ~StreamStore();
    Stream getStreambyId(uint64_t sid);
    uint64_t getStreamIdTalkerandListener(inet::MACAddress  src, inet::MACAddress dst, uint16_t vlanid);
    void addStreamToStore(uint64_t sid,Stream s);
    void printStreamToStore();
    void updateStreamPathinStore(uint64_t sid, std::vector<int> assignedPath, int pathIndex, float rate);
};


#endif /* OPENFLOW_OPENFLOW_CONTROLLER_STREAMSTORE_H_ */

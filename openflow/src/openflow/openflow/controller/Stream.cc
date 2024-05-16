/*
 * Stream.cc
 *
 *  Created on: Mar 17, 2021
 *      Author: root
 */

#include "openflow/openflow/controller/Stream.h"
#include "openflow/openflow/controller/StreamStore.h"
#include <iostream>
#include <map>
#include <omnetpp.h>

using namespace std;
using namespace inet;



Stream::Stream(){
    sid=-1;
    vlanid = -1;
    talkerInPort=-1;
    sendingPeriod=-1;
    rate=0;
    //talkerSwInfo=other.talkerSwInfo;
    //talker=other.talker;
    // listener=other.listener;
    pathIndex=-1;
   // assignedPath=other.assignedPath;

}


Stream::~Stream() {
    // TODO Auto-generated destructor stub
}


Stream::Stream(const Stream &other){
    sid=other.sid;
    vlanid = other.vlanid;
    talkerInPort=other.talkerInPort;
    sendingPeriod=other.sendingPeriod;
    talkerSwInfo=other.talkerSwInfo;
    talker=other.talker;
    rate=other.rate;
    listener=other.listener;
    pathIndex=other.pathIndex;
    assignedPath=other.assignedPath;
}

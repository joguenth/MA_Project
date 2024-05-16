/*
 * StreamStore.cc
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

map<uint64_t, Stream> RegisteredStreams;

StreamStore::StreamStore(){
}


StreamStore::~StreamStore() {
    // TODO Auto-generated destructor stub
}

Stream StreamStore::getStreambyId(uint64_t sid){
    if (RegisteredStreams.find(sid) != RegisteredStreams.end())
        return RegisteredStreams[sid];
    else
        Stream();
}


uint64_t StreamStore::getStreamIdTalkerandListener(inet::MACAddress  src, inet::MACAddress dst, uint16_t vlanid){
    Stream s;
    uint64_t sid=-1;

    for (auto x = RegisteredStreams.begin(); x != RegisteredStreams.end(); x++) {
        s =x->second;
        if(s.talker==src && s.listener==dst && s.vlanid ==vlanid){
            sid = s.sid;
            break;
        }
    }
    return sid;
}


void StreamStore::printStreamToStore(){

    std::ofstream fs;

    std::string fid="StreamStore";
    std::string filename="/root/DynTssdn/SDN4CoRE/examples/tsnMtd/getnet/results/"+fid+".txt";
    fs.open(filename.c_str(), ios::out | ios::app ); //append mode


    fs<<"########  Stream Store Content ########"<<endl;
    for (auto x = RegisteredStreams.begin(); x != RegisteredStreams.end(); x++) {
        uint64_t id= x->first;
        Stream s =x->second;

        fs<<"Stream with id of "<<id<<" has read from Stream Store: "<<
                "\t"<<" inport "<<s.talkerInPort<<
                "\t"<<" talkerSwInfo "<<(s.talkerSwInfo)->getMacAddress()<<
                "\t"<<" vlanid "<<s.vlanid<<
                "\t"<<" rate "<<s.rate<<
                "\t"<<" talker "<<s.talker<<
                "\t"<<" listener "<<s.listener<<
                "\t"<<" pathIndex "<<s.pathIndex<<
                "\t"<<" assignedPath ";

        for (auto x: s.assignedPath)
            fs<<x<<" ";


        fs<<endl;
    }
    fs<<"########  ########  ########"<<endl;
}

void StreamStore::addStreamToStore(uint64_t sid, Stream s){
    RegisteredStreams[sid]=s;
}


void StreamStore::updateStreamPathinStore(uint64_t sid, std::vector<int> assignedPath, int pathIndex, float rate){
    for (auto x = RegisteredStreams.begin(); x != RegisteredStreams.end(); x++) {
        if(sid == x->first){
            Stream s =x->second;
            s.assignedPath = assignedPath;
            s.pathIndex = pathIndex;
            s.rate= rate;
            RegisteredStreams[sid]=s;
            break;
        }
    }
}




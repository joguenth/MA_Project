/*
 * IEEE8021QSRPLikeTrafficSinkApp.cc
 *
 *  Created on: Apr 23, 2022
 *      Author: root
 */


//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#include "IEEE8021QSRPLikeTrafficSinkApp.h"
//CoRE4INET
#include "core4inet/utilities/ConfigFunctions.h"

using namespace std;
namespace CoRE4INET {

Define_Module(IEEE8021QSRPLikeTrafficSinkApp);

void IEEE8021QSRPLikeTrafficSinkApp::initialize()
{
    BGTrafficSinkApp::initialize();
    handleParameterChange(nullptr);
    for (unsigned int i = 0; i < this->numPCP; i++)
    {
        simsignal_t signalPk = registerSignal(("rxQPcp" + std::to_string(i) + "Pk").c_str());
        cProperty* statisticTemplate = getProperties()->get("statisticTemplate", "rxQPcpPk");
        getEnvir()->addResultRecorders(this, signalPk, ("rxQPcp" + std::to_string(i) + "Pk").c_str(), statisticTemplate);
        statisticTemplate = getProperties()->get("statisticTemplate", "rxQPcpBytes");
        getEnvir()->addResultRecorders(this, signalPk, ("rxQPcp" + std::to_string(i) + "Bytes").c_str(), statisticTemplate);

        this->rxQPcpPkSignals.push_back(signalPk);
    }
    received=0;
    avg_E2Enetwide=0;
}

void IEEE8021QSRPLikeTrafficSinkApp::handleMessage(cMessage *msg)
{
    if (EthernetIIFrameWithQTag *qframe = dynamic_cast<EthernetIIFrameWithQTag*>(msg)){
        if (address.isUnspecified() || qframe->getSrc() == address){
            int pcp = qframe->getPcp();
            emit(this->rxQPcpPkSignals[pcp], qframe);
            //save frame
            saveTTframe(qframe);
            received++;
        }
    }
    delete msg;
}

void IEEE8021QSRPLikeTrafficSinkApp::handleParameterChange(const char* parname)
{
    BGTrafficSinkApp::handleParameterChange(parname);
    if (!parname || !strcmp(parname, "numPCP"))
    {
        this->numPCP = static_cast<unsigned int>(parameterULongCheckRange(par("numPCP"), 1, std::numeric_limits<int>::max()));
    }
}


void IEEE8021QSRPLikeTrafficSinkApp::saveTTframe(EthernetIIFrameWithQTag *qframe){
    //save TT frame
     ReceivedTTFrameLatencies[qframe->getStreamID()].push_back(qframe->getArrivalTime()-qframe->getCreationTime());
   /*  cout<<"Received Frame Latency check: StreamID: "<<qframe->getStreamID()<<", "<<endl;
     ofstream fp;
               fp.open ("e2elog.txt", ios_base::app);
               fp <<"Received Frame Latency check: StreamID: "<<qframe->getStreamID()<<"\n";
               fp.close();*/
}



void IEEE8021QSRPLikeTrafficSinkApp::finish() {

    double ave_E2Elatency=0;
    double ave_E2Enetwide=0;
    uint16_t key;
    if(ReceivedTTFrameLatencies.size()!=0){
        for (auto n : ReceivedTTFrameLatencies){
            key = n.first;
            std::vector<simtime_t> value = n.second;

            double tmpSum=0;
            for (auto n : value)
                tmpSum+=n.dbl();

            ave_E2Elatency=tmpSum/value.size();
            ave_E2Enetwide+=ave_E2Elatency;
            cout<<"Average E2E latency for stream "<<key<<" => " <<ave_E2Elatency<<" sec"<<endl;
        }

        ave_E2Enetwide/=ReceivedTTFrameLatencies.size();
//       cout<<"Average E2E latency for all streams => " <<ave_E2Enetwide<<" sec"<<endl;
        //include logging of average E2E latencies per stream to e2elog.txt
        ofstream fp;
          fp.open ("e2elog.txt", ios_base::app);
          fp <<"Stream"<<key<<"  => " << ave_E2Enetwide<<" sec. \n";
          fp.close();
//        avg_E2Enetwide=ave_E2Elatency;

        ReceivedTTFrameLatencies.clear();
    }

    //note: results can be extended depending on the purpose, this is just a simple showcase
    //solution: outputting related results to the files for further processing

}


} //namespace



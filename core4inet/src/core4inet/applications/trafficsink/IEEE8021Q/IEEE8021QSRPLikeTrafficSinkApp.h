/*
 * IEEE8021QSRPLikeTrafficSinkApp.h
 *
 *  Created on: Apr 23, 2022
 *      Author: root
 */

#ifndef CORE4INET_APPLICATIONS_TRAFFICSINK_IEEE8021Q_IEEE8021QSRPLIKETRAFFICSINKAPP_H_
#define CORE4INET_APPLICATIONS_TRAFFICSINK_IEEE8021Q_IEEE8021QSRPLIKETRAFFICSINKAPP_H_


#include <omnetpp.h>
// inlcude iostream and string libraries
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include "core4inet/applications/trafficsink/base/BGTrafficSinkApp.h"
#include "core4inet/linklayer/ethernet/base/EtherFrameWithQTag_m.h"

#include <map>
#include <tuple>
#include <vector>
#include <string>
using namespace omnetpp;

namespace CoRE4INET {
class IEEE8021QSRPLikeTrafficSinkApp : public virtual BGTrafficSinkApp
{
    private:
        /**
         * @brief Number of priorities.
         */
        unsigned int numPCP;

    protected:
        /**
         * @brief Signals that are emitted when a frame is received.
         */
        std::vector<simsignal_t> rxQPcpPkSignals;

        /**
         * @brief Initialization of the module. Sends activator message
         */
        virtual void initialize() override;

        /**
         * @brief collects incoming message and writes statistics.
         *
         * @param msg incoming frame
         */
        virtual void handleMessage(cMessage *msg) override;

        /**
         * @brief Indicates a parameter has changed.
         *
         * @param parname Name of the changed parameter or nullptr if multiple parameter changed.
         */
        virtual void handleParameterChange(const char* parname) override;

        std::map<uint16_t,std::vector<simtime_t>> ReceivedTTFrameLatencies;

        virtual void saveTTframe(CoRE4INET::EthernetIIFrameWithQTag *qframe);


        void finish();
        int received;
        double avg_E2Enetwide;
};

} //namespace

#endif /* CORE4INET_APPLICATIONS_TRAFFICSINK_IEEE8021Q_IEEE8021QSRPLIKETRAFFICSINKAPP_H_ */

/*
 * IEEE8021QSRPLikeTrafficSourceApp.h
 *
 *  Created on: Apr 21, 2022
 *      Author: root
 */

#ifndef CORE4INET_APPLICATIONS_TRAFFICSOURCE_IEEE8021Q_IEEE8021QSRPLIKETRAFFICSOURCEAPP_H_
#define CORE4INET_APPLICATIONS_TRAFFICSOURCE_IEEE8021Q_IEEE8021QSRPLIKETRAFFICSOURCEAPP_H_

//CoRE4INET
#include "core4inet/applications/trafficsource/base/TrafficSourceAppBase.h"
#include "core4inet/applications/trafficsource/IEEE8021Q/IEEE8021QTrafficSourceApp.h"

//CoRE4INET
#include "core4inet/base/CoRE4INET_Defs.h"
#include "core4inet/base/avb/AVBDefs.h"
#include "core4inet/linklayer/contract/ExtendedIeee802Ctrl_m.h"
#include "core4inet/buffer/base/BGBuffer.h"
#include "core4inet/utilities/ConfigFunctions.h"
#include "core4inet/linklayer/ethernet/base/EtherFrameWithQTag_m.h"
#include "core4inet/linklayer/ethernet/avb/SRPFrame_m.h"

//INET
#include "inet/linklayer/common/MACAddress.h"

namespace CoRE4INET {

class IEEE8021QSRPLikeTrafficSourceApp : public virtual IEEE8021QTrafficSourceApp
{
    protected:
        unsigned long streamID;
        bool isStreaming;
        simtime_t streamStartTime;
        inet::MACAddress srcAddress;

    public:
        IEEE8021QSRPLikeTrafficSourceApp();

    protected:

        /**
         * @brief Initialization of the module. Sends activator message
         */
        virtual void initialize() override;

        /**
         * @brief handle self messages to send frames
         *
         *
         * @param msg incoming self messages
         */
        virtual void handleMessage(cMessage *msg) override;

        /**
         * @brief Generates and sends a new Message.
         *
         * The message is sent to the buffer.
         * The size is defined by the payload parameter of the module.
         */
        virtual void sendMessage();

        /**
         * @brief Indicates a parameter has changed.
         *
         * @param parname Name of the changed parameter or nullptr if multiple parameter changed.
         */
        virtual void handleParameterChange(const char* parname) override;

        void sendTAMessage();
};

} //namespace

#endif /* CORE4INET_APPLICATIONS_TRAFFICSOURCE_IEEE8021Q_IEEE8021QSRPLIKETRAFFICSOURCEAPP_H_ */

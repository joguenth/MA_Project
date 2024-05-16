/*
 * Host_Profile.h
 *
 *  Created on: Jul 19, 2020
 *      Author: root
 */

#ifndef OPENFLOW_OPENFLOW_CONTROLLER_HOST_PROFILE_H_
#define OPENFLOW_OPENFLOW_CONTROLLER_HOST_PROFILE_H_

#include <openflow/openflow/protocol/OpenFlow.h>
#include "inet/transportlayer/contract/tcp/TCPSocket.h"

namespace openflow{


class Host_Profile {
    public:
        Host_Profile();

        std::string getMacAddress() const;
        void setMacAddress(std::string macAddress);

        int getConnectedSw_topo_index() const;
        void setConnectedSw_topo_index(int t);

        int getTopo_index() const;
        void setTopo_index(int ti);

    protected:
        std::string macAddress;
        int connectedSw_topo_index;
        int topoindex; //own topology index


};

} /*end namespace ofp*/





#endif /* OPENFLOW_OPENFLOW_CONTROLLER_HOST_PROFILE_H_ */

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

package sdn4core.examples.tsnMtd.getnet;

import sdn4core.controller.base.NetConfOpenFlowController;
import inet.node.ethernet.Eth100M;
import inet.common.misc.ThruputMeteringChannel;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import inet.common.scenario.ScenarioManager;
import inet.node.ethernet.EtherSwitch;
import sdn4core.switch.ieee8021qbv.IEEE8021QbvOFNCEdgeSwitch;
import sdn4core.switch.ieee8021qbv.IEEE8021QbvOFNCSwitch;
import core4inet.nodes.ethernet.IEEE8021Q.IEEE8021QEtherHost;

module EdgeSwitch extends IEEE8021QbvOFNCEdgeSwitch
{
    @display("i=device/switch;i2=OpenFlow-Logo-small");
}

module Switch extends IEEE8021QbvOFNCSwitch
{
    @display("i=device/switch;i2=OpenFlow-Logo-small");
}

module Host extends IEEE8021QEtherHost
{
    @display("bgb=487,314"); //background size, color, border
}


network getnet
{
    parameters:
        @display("bgb=1000.0,500.0,white");

    types:
        channel controlplane extends ThruputMeteringChannel
        {
            delay = 1us;
            datarate = 1Gbps;
            thruputDisplayFormat = "u";
        }

        //do not forget to change it also in the monitoring controller app
        channel backbone extends Eth100M
        {
            //delay = 1us;
            length = 5m;
        }

        channel edge extends Eth100M
        {
            //delay = 1us;
            length = 10m;
        }
    submodules:
        configurator: IPv4NetworkConfigurator;
        //scenarioManager: ScenarioManager;
        open_flow_controller1: NetConfOpenFlowController;
        switch1: EdgeSwitch {
            gates:
                gateDataPlane[11];
        }
        switch2: Switch {
            gates:
                gateDataPlane[4];
        }
        switch3: Switch {
            gates:
                gateDataPlane[3];
        }
        switch4: EdgeSwitch {
            @display("p=391,139");
            gates:
                gateDataPlane[11];
        }
        switch5: Switch {
            gates:
                gateDataPlane[3];
        }
        switch6: EdgeSwitch {
            gates:
                gateDataPlane[12];
        }
        switch7: EdgeSwitch {
            gates:
                gateDataPlane[12];
        }


        ethswitch: EtherSwitch;
        host1: Host;
        host2: Host;
        host3: Host;
        host4: Host;
        host5: Host;
        host6: Host;
        host7: Host;
        host8: Host;
        host9: Host;
        host10: Host;
        host11: Host;
        host12: Host;
        host13: Host;
        host14: Host;
        host15: Host;
        host16: Host;
        host17: Host;
        host18: Host;
        host19: Host;
        host20: Host;
        host21: Host;
        host22: Host;
        host23: Host;
        host24: Host;
        host25: Host;
        host26: Host;
        host27: Host;
        host28: Host;
        host29: Host;
        host30: Host;
        host31: Host;
        host32: Host;
        host33: Host;
        host34: Host;
        host35: Host;
        host36: Host;
        host37: Host;
        host38: Host;
        host39: Host;
        host40: Host;
    connections:
        switch1.gateDataPlane[0] <--> backbone <--> switch2.gateDataPlane[0];
        switch2.gateDataPlane[1] <--> backbone <--> switch3.gateDataPlane[0];
        switch2.gateDataPlane[2] <--> backbone <--> switch5.gateDataPlane[0];
        switch2.gateDataPlane[3] <--> backbone <--> switch7.gateDataPlane[0];
        switch3.gateDataPlane[1] <--> backbone <--> switch4.gateDataPlane[0];
        switch3.gateDataPlane[2] <--> backbone <--> switch5.gateDataPlane[1];
        switch5.gateDataPlane[2] <--> backbone <--> switch6.gateDataPlane[0];
        switch6.gateDataPlane[1] <--> backbone <--> switch7.gateDataPlane[1];

        switch1.gateDataPlane[1] <--> edge <--> host1.ethg;
        switch1.gateDataPlane[2] <--> edge <--> host2.ethg;
        switch1.gateDataPlane[3] <--> edge <--> host3.ethg;
        switch1.gateDataPlane[4] <--> edge <--> host4.ethg;
        switch1.gateDataPlane[5] <--> edge <--> host5.ethg;
        switch1.gateDataPlane[6] <--> edge <--> host6.ethg;
        switch1.gateDataPlane[7] <--> edge <--> host7.ethg;
        switch1.gateDataPlane[8] <--> edge <--> host8.ethg;
        switch1.gateDataPlane[9] <--> edge <--> host9.ethg;
        switch1.gateDataPlane[10] <--> edge <--> host10.ethg;
        switch4.gateDataPlane[1] <--> edge <--> host11.ethg;
        switch4.gateDataPlane[2] <--> edge <--> host12.ethg;
        switch4.gateDataPlane[3] <--> edge <--> host13.ethg;
        switch4.gateDataPlane[4] <--> edge <--> host14.ethg;
        switch4.gateDataPlane[5] <--> edge <--> host15.ethg;
        switch4.gateDataPlane[6] <--> edge <--> host16.ethg;
        switch4.gateDataPlane[7] <--> edge <--> host17.ethg;
        switch4.gateDataPlane[8] <--> edge <--> host18.ethg;
        switch4.gateDataPlane[9] <--> edge <--> host19.ethg;
        switch4.gateDataPlane[10] <--> edge <--> host20.ethg;
        switch6.gateDataPlane[2] <--> edge <--> host21.ethg;
        switch6.gateDataPlane[3] <--> edge <--> host22.ethg;
        switch6.gateDataPlane[4] <--> edge <--> host23.ethg;
        switch6.gateDataPlane[5] <--> edge <--> host24.ethg;
        switch6.gateDataPlane[6] <--> edge <--> host25.ethg;
        switch6.gateDataPlane[7] <--> edge <--> host26.ethg;
        switch6.gateDataPlane[8] <--> edge <--> host27.ethg;
        switch6.gateDataPlane[9] <--> edge <--> host28.ethg;
        switch6.gateDataPlane[10] <--> edge <--> host29.ethg;
        switch6.gateDataPlane[11] <--> edge <--> host30.ethg;
        switch7.gateDataPlane[2] <--> edge <--> host31.ethg;
        switch7.gateDataPlane[3] <--> edge <--> host32.ethg;
        switch7.gateDataPlane[4] <--> edge <--> host33.ethg;
        switch7.gateDataPlane[5] <--> edge <--> host34.ethg;
        switch7.gateDataPlane[6] <--> edge <--> host35.ethg;
        switch7.gateDataPlane[7] <--> edge <--> host36.ethg;
        switch7.gateDataPlane[8] <--> edge <--> host37.ethg;
        switch7.gateDataPlane[9] <--> edge <--> host38.ethg;
        switch7.gateDataPlane[10] <--> edge <--> host39.ethg;
        switch7.gateDataPlane[11] <--> edge <--> host40.ethg;

        ethswitch.ethg++ <--> controlplane <--> switch1.gateControlPlane;
        ethswitch.ethg++ <--> controlplane <--> switch2.gateControlPlane;
        ethswitch.ethg++ <--> controlplane <--> switch3.gateControlPlane;
        ethswitch.ethg++ <--> controlplane <--> switch4.gateControlPlane;
        ethswitch.ethg++ <--> controlplane <--> switch5.gateControlPlane;
        ethswitch.ethg++ <--> controlplane <--> switch6.gateControlPlane;
        ethswitch.ethg++ <--> controlplane <--> switch7.gateControlPlane;
        ethswitch.ethg++ <--> controlplane <--> open_flow_controller1.ethg++;
}

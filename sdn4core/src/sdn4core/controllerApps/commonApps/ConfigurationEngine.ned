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

package sdn4core.controllerApps.commonApps;
import openflow.controllerApps.AbstractControllerApp;

simple ConfigurationEngine like AbstractControllerApp
{
    parameters:
        @class(SDN4CoRE::ConfigurationEngine);
        @display("i=block/app"); 
        int flowModHardTimeOut @unit("s")= default(100s); //hard timeout for flow entries
        int flowModIdleTimeOut @unit("s")= default(100s); //idle timeout for flow entries 
        bool isTaggingEnabled = default(false);   
        int priority = default(1);   
}

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

package sdn4core.switch.ieee8021qbv.edgeAgent;
import sdn4core.switch.base.engine.OF_SwitchAgent;

simple Edge_OF_SwitchAgent extends OF_SwitchAgent
{
    parameters:
        @class(SDN4CoRE::Edge_OF_SwitchAgent);
    	
        //SRP Table module, default name is srpTable
        string srpTable = default("^.srpTable");
        string srpProtocolModule = default("^.srpProtocol");
    	bool isTaggingEnabled = default(false);
   	gates:
   	    //SRP message in from SRP protocol module
        input srpIn @loose;
        //SRP message out to SRP protocol module
        output srpOut @loose;
    	    
    
}

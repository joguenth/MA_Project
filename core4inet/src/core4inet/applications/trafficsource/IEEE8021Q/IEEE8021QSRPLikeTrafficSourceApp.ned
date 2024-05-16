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

package core4inet.applications.trafficsource.IEEE8021Q;
import core4inet.applications.trafficsource.base.BGTrafficSourceApp;

simple IEEE8021QSRPLikeTrafficSourceApp extends IEEE8021QTrafficSourceApp
{
    parameters:
        @class(IEEE8021QSRPLikeTrafficSourceApp);
        @display("i=block/source,blue");
        
        //ID of the Stream
        int streamID = default(0);  
        bool isStreaming = default(false); 
 		string srcAddress ;
        
     gates:
        //Input gate for the incoming best-effort messages
        input in ;//@directIn @labels(EtherFrame);
}

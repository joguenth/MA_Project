/*
 * Assignment.h
 *
 *  Created on: Mar 18, 2021
 *      Author: Nurefsan Sertbas Bulbul
 */

#ifndef SDN4CORE_CONTROLLERAPPS_COMMONAPPS_ASSIGNMENT_H_
#define SDN4CORE_CONTROLLERAPPS_COMMONAPPS_ASSIGNMENT_H_

#include <vector>
#include <string>

using namespace std;
namespace SDN4CoRE{


class Assignment {
public:
    int demand_index;
    float data;
    std::vector<int> path;
    int path_index;

    Assignment();
    Assignment(int i, float d, vector<int> p, int j);

    Assignment(const Assignment &a);

    Assignment&  operator=(const Assignment& a);
    bool  operator==(const Assignment& a);
};

} /*end namespace ofp*/


#endif /* SDN4CORE_CONTROLLERAPPS_COMMONAPPS_ASSIGNMENT_H_ */

/* Rise.h
*
* Author: Erdem Kara
*
*/

#ifndef RISE_HEADER
#define RISE_HEADER

#include "UnstableManeuvers.h"

// class for Rise Maneuver
class Rise : public UnstableManeuvers {

public:

	Rise();
	~Rise(); 

	void print();
	double getDistance();
	double getFuel();

};

#endif

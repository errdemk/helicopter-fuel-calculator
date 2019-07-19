/* Suspended.h
*
* Author: Erdem Kara
*
*/

#ifndef SUSPENDED_HEADER
#define SUSPENDED_HEADER

#include "StableManeuvers.h"

// class for Suspended Flight Maneuver
class Suspended : public StableManeuvers {

public:

	Suspended();
	~Suspended();

	void print();
	double getFuel();

};

#endif
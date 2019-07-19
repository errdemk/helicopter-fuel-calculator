/* Straight.h
*
* Author: Erdem Kara
*
*/

#ifndef STRAIGHT_HEADER
#define STRAIGHT_HEADER

#include "StraightManeuvers.h"

// class for Straight Flight Maneuver
class Straight : public StraightManeuvers {

public:

	Straight();
	~Straight(); 

	void print();
	double getFuel();

};

#endif


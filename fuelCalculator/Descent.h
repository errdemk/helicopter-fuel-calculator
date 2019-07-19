/* Descent.h
*
* Author: Erdem Kara
*
*/

#ifndef DESCENT_HEADER
#define DESCENT_HEADER

#include "UnstableManeuvers.h"

// class for Descent Maneuver
class Descent : public UnstableManeuvers {

public:

	Descent();
	~Descent();

	void print();
	double getDistance();
	double getFuel();

};

#endif


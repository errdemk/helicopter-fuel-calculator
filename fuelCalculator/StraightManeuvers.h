/* StraightManeuvers.h
*
* Author: Erdem Kara
*
*/

#ifndef STRAIGHTMANEUVERS_HEADER
#define STRAIGHTMANEUVERS_HEADER

#include "Maneuvers.h"

// abstract class for Straight Flight Maneuvers
class StraightManeuvers : public Maneuvers {

public:

	StraightManeuvers();
	~StraightManeuvers(); 

	void setDistance(double);
	void setSpeed(double);
	void setFcv(double);

protected:

	double distance;
	double speed;

};

#endif

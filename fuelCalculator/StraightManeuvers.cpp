/* StraightManeuvers.cpp
*
* Author: Erdem Kara
*
*/

#include "StraightManeuvers.h"

StraightManeuvers::StraightManeuvers() {
	distance = 0;
	speed = 0;
}

StraightManeuvers::~StraightManeuvers() {}

void StraightManeuvers::setDistance(double distanceIn) {
	distance = distanceIn;
}

void StraightManeuvers::setSpeed(double speedIn) {
	speed = speedIn;
}

void StraightManeuvers::setFcv(double fcvIn) {
	fcv = fcvIn;
}
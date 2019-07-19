/* UnstableManeuvers.cpp
*
* Author: Erdem Kara
*
*/

#include "UnstableManeuvers.h"

UnstableManeuvers::UnstableManeuvers() {
	up = 0;
	down = 0;
	speed = 0;
}

UnstableManeuvers::~UnstableManeuvers() {} 

void UnstableManeuvers::setUp(double upIn) {
	up = upIn;
}

void UnstableManeuvers::setDown(double downIn) {
	down = downIn;
}

void UnstableManeuvers::setSpeed(double speedIn) {
	speed = speedIn;
}

void UnstableManeuvers::setFcv(double fcvIn) {
	fcv = fcvIn;
}
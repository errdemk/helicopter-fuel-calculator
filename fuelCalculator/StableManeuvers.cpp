/* StableManeuvers.cpp
*
* Author: Erdem Kara
*
*/

#include "StableManeuvers.h"

StableManeuvers::StableManeuvers() {
	ftime = 0;
}

StableManeuvers::~StableManeuvers() {}

void StableManeuvers::setTime(double ftimeIn) {
	ftime = ftimeIn;
}

double StableManeuvers::getTime() {
	return ftime;
}

void StableManeuvers::setFcv(double fcvIn) {
	fcv = fcvIn;
}
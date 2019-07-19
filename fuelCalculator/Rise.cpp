/* Rise.cpp
*
* Author: Erdem Kara
*
*/

#include <iostream>
#include "Rise.h"

Rise::Rise() {}
Rise::~Rise() {}

void Rise::print() {
	std::cout << "Entered Rise Maneuver..." << std::endl;
}

double Rise::getDistance() { 
	return (up - down);
}

double Rise::getFuel() {
	return ((getDistance() / speed)) * fcv;
}
/* Suspended.cpp
*
* Author: Erdem Kara
*
*/

#include <iostream>
#include "Suspended.h"

#define SEC 60

Suspended::Suspended() {}
Suspended::~Suspended() {}

void Suspended::print() {
	std::cout << "Entered Suspended Flight Maneuver..." << std::endl;
}

double Suspended::getFuel() {
	return (ftime * SEC) * fcv;
}
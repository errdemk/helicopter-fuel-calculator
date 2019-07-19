/* Straight.cpp
*
* Author: Erdem Kara
*
*/

#include <iostream>
#include "Straight.h"

Straight::Straight() {}
Straight::~Straight() {}

void Straight::print() {
	std::cout << "Entered Straight Flight Maneuver..." << std::endl;
}

double Straight::getFuel() {
	return (distance / speed) * fcv;
}

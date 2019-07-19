/* Descent.cpp
*
* Author: Erdem Kara
*
*/

#include <iostream>
#include "Descent.h"

Descent::Descent() {}
Descent::~Descent() {} 

void Descent::print() {
	std::cout << "Entered Descent Maneuver..." << std::endl;
}

double Descent::getDistance() {
	return (up - down);
}

double Descent::getFuel() {
	return ((getDistance() / speed)) * fcv;
}
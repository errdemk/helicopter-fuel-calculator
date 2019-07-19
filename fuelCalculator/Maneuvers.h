/* Maneuvers.h
*
* Author: Erdem Kara
*
*/

#ifndef MANEUVERS_HEADER
#define MANEUVERS_HEADER

// abstract class for all Maneuvers
class Maneuvers {
	public:
		 
		Maneuvers();
		~Maneuvers();
		virtual void print() = 0;
		virtual double getFuel() = 0;

	protected:

		double fcv;	// fuel consumption value
};

#endif
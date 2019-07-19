/* StableManeuvers.h
*
* Author: Erdem Kara
*
*/

#ifndef STABLEMANEUVERS_HEADER
#define STABLEMANEUVERS_HEADER

#include "Maneuvers.h"

// abstract class for Stable Maneuvers which is Suspended Flight Maneuver for that case
class StableManeuvers : public Maneuvers {

	public:

		StableManeuvers();
		~StableManeuvers();
		 
		void setTime(double);
		double getTime();

		void setFcv(double);

	protected:

		double ftime;

};

#endif
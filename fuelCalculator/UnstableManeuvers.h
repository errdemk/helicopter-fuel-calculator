/* UnstableManeuvers.h
*
* Author: Erdem Kara
*
*/

#ifndef UNSTABLEMANEUVERS_HEADER
#define UNSTABLEMANEUVERS_HEADER

#include "Maneuvers.h"

// abstract class for Unstable Maneuvers which are Rise and Descent Maneuvers for that case
class UnstableManeuvers : public Maneuvers {

	public:

		UnstableManeuvers();
		~UnstableManeuvers();

		virtual double getDistance() = 0;

		void setUp(double);
		void setDown(double);
		void setSpeed(double);
		void setFcv(double);

	protected:

		double up;
		double down;
		double speed;

};

#endif

/* LayerWin.hpp
*
* Author: Erdem Kara
*
*/

#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Float_Input.H> 

#include "Suspended.h"
#include "Rise.h"
#include "Descent.h"
#include "Straight.h"

double ftime = 0;
double fcv = 0;
double fuel = 0;
double up = 0;
double down = 0;
double speed = -1;
double dist = 0;

///////////////////////////////////////////////////////////////////////////////
/////// FLTK Class and Functions for GUI

// class for creating new layer to get user input after selecting any maneuver
class LayerWin {

	public:

		LayerWin(int layers) : nlayers(layers), win(0) {}
		~LayerWin() { delete win; }

		void Create() {
			int wid = 600, hight = 300;

			if (nlayers == 1) {
				win = new Fl_Window(wid, hight, "Suspended Flight Maneuver");
				win->set_modal();

				Fl_Float_Input *in1 = new Fl_Float_Input(250, 80, 180, 20, "Suspended Flight Time (mins): ");
				in1->callback((Fl_Callback*)cb_time);
				in1->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

				Fl_Float_Input *in2 = new Fl_Float_Input(250, 120, 180, 20, "Fuel Consumption Value (kg/sec): ");
				in2->callback((Fl_Callback*)cb_fcv);
				in2->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

				Fl_Button* btnClose = new Fl_Button(10, 270, 100, 20, "Submit");
				btnClose->callback(susClose, this);
				win->end();
				win->show();
			}

			else if (nlayers == 2) {
				win = new Fl_Window(wid, hight, "Rise Maneuver");
				win->set_modal();

				Fl_Float_Input *in1 = new Fl_Float_Input(250, 80, 180, 20, "Higher Altitude (meters): ");
				in1->callback((Fl_Callback*)cb_up);
				in1->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

				Fl_Float_Input *in2 = new Fl_Float_Input(250, 120, 180, 20, "Lower Altitude (meters): ");
				in2->callback((Fl_Callback*)cb_down);
				in2->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

				Fl_Float_Input *in3 = new Fl_Float_Input(250, 160, 180, 20, "Rise Speed (meter/sec): ");
				in3->callback((Fl_Callback*)cb_speed);
				in3->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

				Fl_Float_Input *in4 = new Fl_Float_Input(250, 200, 180, 20, "Fuel Consumption Value (kg/sec): ");
				in4->callback((Fl_Callback*)cb_fcv);
				in4->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

				Fl_Button* btnClose = new Fl_Button(10, 270, 100, 20, "Submit");
				btnClose->callback(riseClose, this);
				win->end();
				win->show();
			}

			else if (nlayers == 3) {
				win = new Fl_Window(wid, hight, "Descent Maneuver");
				win->set_modal();

				Fl_Float_Input *in1 = new Fl_Float_Input(250, 80, 180, 20, "Higher Altitude (meters): ");
				in1->callback((Fl_Callback*)cb_up);
				in1->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

				Fl_Float_Input *in2 = new Fl_Float_Input(250, 120, 180, 20, "Lower Altitude (meters): ");
				in2->callback((Fl_Callback*)cb_down);
				in2->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

				Fl_Float_Input *in3 = new Fl_Float_Input(250, 160, 180, 20, "Descent Speed (meter/sec): ");
				in3->callback((Fl_Callback*)cb_speed);
				in3->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

				Fl_Float_Input *in4 = new Fl_Float_Input(250, 200, 180, 20, "Fuel Consumption Value (kg/sec): ");
				in4->callback((Fl_Callback*)cb_fcv);
				in4->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

				Fl_Button* btnClose = new Fl_Button(10, 270, 100, 20, "Submit");
				btnClose->callback(desClose, this);
				win->end();
				win->show();
			}

			else if (nlayers == 4) {
				win = new Fl_Window(wid, hight, "Straight Flight Maneuver");
				win->set_modal();

				Fl_Float_Input *in1 = new Fl_Float_Input(250, 80, 180, 20, "Straight Flight Distance (meters): ");
				in1->callback((Fl_Callback*)cb_dist);
				in1->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

				Fl_Float_Input *in2 = new Fl_Float_Input(250, 120, 180, 20, "Flight Speed (meter/sec): ");
				in2->callback((Fl_Callback*)cb_speed);
				in2->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

				Fl_Float_Input *in3 = new Fl_Float_Input(250, 160, 180, 20, "Fuel Consumption Value (kg/sec): ");
				in3->callback((Fl_Callback*)cb_fcv);
				in3->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

				Fl_Button* btnClose = new Fl_Button(10, 270, 100, 20, "Submit");
				btnClose->callback(strClose, this);
				win->end();
				win->show();
			}
		}

		static void cb_time(Fl_Input* in, void*) {
			ftime = strtod(in->value(), NULL);
			std::cout << ftime << std::endl;
		}

		static void cb_dist(Fl_Input* in, void*) {
			dist = strtod(in->value(), NULL);
			std::cout << dist << std::endl;
		}

		static void cb_up(Fl_Input* in, void*) {
			up = strtod(in->value(), NULL);
			std::cout << up << std::endl;
		}

		static void cb_down(Fl_Input* in, void*) {
			down = strtod(in->value(), NULL);
			std::cout << down << std::endl;
		}

		static void cb_speed(Fl_Input* in, void*) {
			speed = strtod(in->value(), NULL);
			std::cout << speed << std::endl;
		}

		static void cb_fcv(Fl_Input* in, void*) {
			fcv = strtod(in->value(), NULL);
			std::cout << fcv << std::endl;
		}

		static void susClose(Fl_Widget* w, void* client) {
			Suspended su;
			su.print();
			su.setTime(ftime);
			su.setFcv(fcv);

			std::cout << su.getFuel() << std::endl;
			fuel += su.getFuel();

			ftime = 0; fcv = 0;

			LayerWin* self = (LayerWin*)client;
			delete self;
		}

		static void riseClose(Fl_Widget* w, void* client) {
			Rise r;
			r.print();
			r.setUp(up);
			r.setDown(down);
			r.setSpeed(speed);
			r.setFcv(fcv);

			std::cout << r.getFuel() << std::endl;
			fuel += r.getFuel();

			up = 0; down = 0; speed = -1; fcv = 0;

			LayerWin* self = (LayerWin*)client;
			delete self;
		}

		static void desClose(Fl_Widget* w, void* client) {
			Descent d;
			d.print();
			d.setUp(up);
			d.setDown(down);
			d.setSpeed(speed);
			d.setFcv(fcv);

			std::cout << d.getFuel() << std::endl;
			fuel += d.getFuel();

			up = 0; down = 0; speed = -1; fcv = 0;

			LayerWin* self = (LayerWin*)client;
			delete self;
		}

		static void strClose(Fl_Widget* w, void* client) {
			Straight st;
			st.print();
			st.setDistance(dist);
			st.setSpeed(speed);
			st.setFcv(fcv);

			std::cout << st.getFuel() << std::endl;
			fuel += st.getFuel();

			dist = 0; speed = -1; fcv = 0;

			LayerWin* self = (LayerWin*)client;
			delete self;
		}

	private:

		int nlayers;
		Fl_Window* win;
};
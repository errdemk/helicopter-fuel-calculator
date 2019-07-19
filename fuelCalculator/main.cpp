/* main.cpp
*
* Author: Erdem Kara
*
*/

#include "LayerWin.hpp"
#include <sstream>

Fl_Button *susBut = new Fl_Button(20, 20, 185, 30, "Suspended Flight Maneuver");
Fl_Button *riseBut = new Fl_Button(20, 60, 185, 30, "Rise Maneuver");
Fl_Button *desBut = new Fl_Button(20, 100, 185, 30, "Descent Maneuver");
Fl_Button *strBut = new Fl_Button(20, 140, 185, 30, "Straight Flight Maneuver");
Fl_Button *exitBut = new Fl_Button(475, 140, 80, 30, "Close"); 
Fl_Output *out = new Fl_Output(375, 80, 180, 20, "Required Fuel (kg): ");
Fl_Button *calc = new Fl_Button(375, 140, 80, 30, "Calculate");

void LayerCB(Fl_Widget* w, long layers) {
	LayerWin* win = new LayerWin(layers);
	win->Create();
}

// callback function to close window
void CloseCB(Fl_Widget* w, void* win) {
	Fl_Window *window = (Fl_Window *)win;
	window->hide();
}

void LayerCB2(Fl_Widget* w, void*) {
	char buf[_CVTBUFSIZE];
	int err;

	err = _gcvt_s(buf, _CVTBUFSIZE, fuel, 10);

	if (err != 0)
		exit(1);

	std::cout << fuel << std::endl;
	std::cout << buf << std::endl;
	out->value(buf);
}

int main(int argc, char **argv) {

	Fl_Window *win = new Fl_Window(600, 200, "Helicopter Fuel Calculator");
	win->color(FL_WHITE);

	// Begin adding children to this window
	win->begin();

	win->add(susBut);
	susBut->callback(LayerCB, 1);

	win->add(riseBut);
	riseBut->callback(LayerCB, 2);

	win->add(desBut);
	desBut->callback(LayerCB, 3);

	win->add(strBut);
	strBut->callback(LayerCB, 4);

	win->add(exitBut);
	exitBut->callback(CloseCB, win);

	win->add(out);
	win->add(calc);
	calc->callback((Fl_Callback*)LayerCB2);

	// Stop adding children to this window
	win->end();

	// Display the window
	win->show();

	return Fl::run();;
}
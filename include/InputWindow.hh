#ifndef INPUTWINDOW_HH_
#define INPUTWINDOW_HH_

#include <ncurses.h>

#include "../include/IWindow.hh"

class InputWindow : public IWindow{
	public:
		InputWindow(int size_y, int size_x, int y, int x);
};

#endif

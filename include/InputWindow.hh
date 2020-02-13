#ifndef INPUTWINDOW_HH_
#define INPUTWINDOW_HH_

#include <ncurses.h>

#include "../include/IWindow.hh"

#define K_ENTER 10

class InputWindow : public IWindow{
	private:
		std::vector<std::string> menu = {"Add new book", "Remove book", "Find", "Sort", "Exit"};
	public:
		InputWindow(int size_y, int size_x, int y, int x);
		int print_content();
		int input_action();
};

#endif

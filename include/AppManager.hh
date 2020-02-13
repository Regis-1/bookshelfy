#ifndef APPMANAGER_HH_
#define APPMANAGER_HH_

#include <ncurses.h>

#include "../include/IWindow.hh"
#include "../include/Bookshelf.hh"
#include "../include/InputWindow.hh"
#include "../include/DialogWindow.hh"

#define INPUTWIN_HEIGHT 3

class AppManager{
	private:
		int scr_max_y, scr_max_x;
		IWindow* iwindow;
		Bookshelf* bookshelf1; 
		Bookshelf* bookshelf2;
		InputWindow* inputwindow;
	public:
		AppManager();
};

#endif
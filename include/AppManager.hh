#ifndef APPMANAGER_HH_
#define APPMANAGER_HH_

#include <ncurses.h>
#include <fstream>

#include "../include/IWindow.hh"
#include "../include/Bookshelf.hh"
#include "../include/InputWindow.hh"
#include "../include/DialogWindow.hh"

#define INPUTWIN_HEIGHT 3

class AppManager{
	private:
		int scr_max_y, scr_max_x;
		Bookshelf* bookshelf1; 
		Bookshelf* bookshelf2;
		InputWindow* inputwindow;
	public:
		AppManager();
		bool main_menu();
		void add_book();
		void remove_book();
		bool sort_books();
		Bookshelf* dwindow_choosing();
		Bookshelf* get_bookshelf(int b_num);
		void read_app_state();
		int will_save();
		void save_app_state();
};

#endif

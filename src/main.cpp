#include<string>

#include<ncurses.h>

#include "../include/AppManager.hh"

int main(int argc, char* argv[]){
	initscr();
	curs_set(0);
	noecho();
	keypad(stdscr, true);
	
	AppManager* appmanager = new AppManager();
	refresh();
	appmanager->main_menu();

	endwin();
	return 0;
}

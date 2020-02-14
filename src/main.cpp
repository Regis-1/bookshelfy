#include<string>

#include<ncurses.h>

#include "../include/AppManager.hh"

int main(int argc, char* argv[]){
	bool exit = false;
	initscr();
	curs_set(0);
	noecho();
	keypad(stdscr, true);
	
	AppManager* appmanager = new AppManager();
	refresh();
	while(!exit)
		exit = appmanager->main_menu();

	return 0;
}

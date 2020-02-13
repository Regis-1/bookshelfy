#include<string>

#include<ncurses.h>

#include "../include/AppManager.hh"

int main(int argc, char* argv[]){
	initscr();
	curs_set(0);
	noecho();
	
	AppManager* appmanager = new AppManager();
	refresh();

	getch();

	endwin();
	return 0;
}

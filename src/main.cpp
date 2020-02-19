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
	appmanager->read_app_state();

	while(!exit)
		exit = appmanager->main_menu();

	if(appmanager->will_save())
		appmanager->save_app_state();

	return 0;
}

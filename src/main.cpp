#include<string>
#include<ncurses.h>

#include "../include/AppManager.hh"

enum EXIT_STATES {SAVE, NOT_SAVE, BACK};

int main(int argc, char* argv[]){
	bool exit = false;
	initscr();
	curs_set(0);
	noecho();
	keypad(stdscr, true);
	
	AppManager* appmanager = new AppManager();
	refresh();
	appmanager->read_app_state();

	while(!exit){
		exit = appmanager->main_menu();

		if(exit)
			switch(appmanager->will_save()){
				case SAVE:
					appmanager->save_app_state();
					break;
				case NOT_SAVE:
					break;
				case BACK:
					exit = false;
					break;
			}
		
	}
	endwin();
	return 0;
}

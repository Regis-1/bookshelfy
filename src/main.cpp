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

	while(!exit){
		exit = appmanager->main_menu();

		if(exit)
			switch(appmanager->will_save()){
				case 0:
					appmanager->save_app_state();
					break;
				case 1:
					break;
				case 2:
					exit = false;
					break;
			}
		
	}
	endwin();
	return 0;
}

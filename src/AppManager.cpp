#include "../include/AppManager.hh"

AppManager::AppManager(){
	getmaxyx(stdscr, scr_max_y, scr_max_x);
	bookshelf1 = new Bookshelf("Read", scr_max_y-INPUTWIN_HEIGHT,scr_max_x/2,0,0);
	bookshelf2 = new Bookshelf("To read", scr_max_y-INPUTWIN_HEIGHT, scr_max_x/2, 0, scr_max_x/2);
	inputwindow = new InputWindow(INPUTWIN_HEIGHT, scr_max_x, scr_max_y - INPUTWIN_HEIGHT, 0);
}

void AppManager::main_menu(){
	IWindow* obj;
	obj = inputwindow;
	int choice = -1;
	while(choice < 0){
		choice = select_option(obj);
	}
	//TUTAJ DALSZA CZESC PROGRAMU ----- TODO_
}

int AppManager::select_option(IWindow* obj){
	if(obj->print_content() != 0)
		return -1;

	return obj->input_action();
}

#include "../include/AppManager.hh"

AppManager::AppManager(){
	getmaxyx(stdscr, scr_max_y, scr_max_x);
	bookshelf1 = new Bookshelf("Read", scr_max_y-INPUTWIN_HEIGHT,scr_max_x/2,0,0);
	bookshelf2 = new Bookshelf("To read", scr_max_y-INPUTWIN_HEIGHT, scr_max_x/2, 0, scr_max_x/2);
	inputwindow = new InputWindow(INPUTWIN_HEIGHT, scr_max_x, scr_max_y - INPUTWIN_HEIGHT, 0);
}

bool AppManager::main_menu(){
	int choice = -1;
	while(choice < 0){
		if(inputwindow->print_content() != 0){
			endwin();
			return true;
		}
		choice = inputwindow->input_action();
	}

	switch(choice){
		case 0:
			add_book();
			break;
		case 1:
			//remove_book();
			break;
		case 2:
			//find_book();
			break;
		case 3:
			//sort_books();
			break;
		case 4:
			exit_bookshelfy();
			return true;
	}
	return false;
}

void AppManager::add_book(){
	inputwindow->input_book_name();
	int dim_dwindow[2] = {10,30};
	DialogWindow* dialogwindow = new DialogWindow("Choose bookshelf:", dim_dwindow[0],dim_dwindow[1], scr_max_y/2 - dim_dwindow[0]/2, scr_max_x/2 - dim_dwindow[1]/2);
	refresh();
	dialogwindow->print_content();
	//Bookshelf * b = dialogwindow->choose_bookshelf();
	//b->add_book();
	//b->update_bookshelf();
}

void AppManager::exit_bookshelfy(){
	endwin();
}

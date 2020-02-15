#include "../include/AppManager.hh"

AppManager::AppManager(){
	getmaxyx(stdscr, scr_max_y, scr_max_x);
	bookshelf1 = new Bookshelf("Read", scr_max_y-INPUTWIN_HEIGHT,scr_max_x/2,0,0);
	bookshelf2 = new Bookshelf("To read", scr_max_y-INPUTWIN_HEIGHT, scr_max_x/2, 0, scr_max_x/2);
	inputwindow = new InputWindow(INPUTWIN_HEIGHT, scr_max_x, scr_max_y - INPUTWIN_HEIGHT, 0);
}

bool AppManager::main_menu(){
	int choice = -1;
	if(inputwindow->menu_loop(&choice))
		return true;

	switch(choice){
		case 0:
			add_book();
			break;
		case 1:
			remove_book();
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
	std::string book_name = inputwindow->input_book_name();
	int dim_dwindow[2] = {10,30};
	DialogWindow* dialogwindow = new DialogWindow("Choose bookshelf:", dim_dwindow[0],dim_dwindow[1], scr_max_y/2 - dim_dwindow[0]/2, scr_max_x/2 - dim_dwindow[1]/2);
	refresh();
	dialogwindow->print_content();
	Bookshelf * b = get_bookshelf(dialogwindow->choose_bookshelf());
	if(b){
		b->add_book(book_name);
	}
	delwin(dialogwindow->get_window());
	delete dialogwindow;
	refresh();
	bookshelf1->print_content(false);
	bookshelf2->print_content(false);
}

void AppManager::remove_book(){
	int dim_dwindow[2] = {10,30};
	DialogWindow* dialogwindow = new DialogWindow("Choose bookshelf:", dim_dwindow[0],dim_dwindow[1], scr_max_y/2 - dim_dwindow[0]/2, scr_max_x/2 - dim_dwindow[1]/2);
	refresh();
	dialogwindow->print_content();
	Bookshelf * b = get_bookshelf(dialogwindow->choose_bookshelf());
	if(b){
		bookshelf1->print_content(false); //to hide dialog window when selecting book
		bookshelf2->print_content(false);
		b->remove_book();
	}
	delwin(dialogwindow->get_window());
	delete dialogwindow;
	refresh();
	bookshelf1->print_content(false);
	bookshelf2->print_content(false);
}

void AppManager::exit_bookshelfy(){
	endwin();
}

Bookshelf* AppManager::get_bookshelf(int b_num){
	std::vector<Bookshelf*> bss = {bookshelf1, bookshelf2};
	if(b_num == (int)bss.size())
		return NULL;
	return bss[b_num];
}

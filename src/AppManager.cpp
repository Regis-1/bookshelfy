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
			find_books();
			break;
		case 3:
			sort_books();
			break;
		case 4:
			return true;
	}
	return false;
}

void AppManager::add_book(){
	std::string book_name = inputwindow->input_book_name(0);
	Bookshelf * b = dwindow_choosing();
	if(b){
		b->add_book(book_name);
	}
	refresh();
	bookshelf1->print_content(false);
	bookshelf2->print_content(false);
}

void AppManager::remove_book(){
	Bookshelf * b = dwindow_choosing();
	if(b){
		bookshelf1->print_content(false);
		bookshelf2->print_content(false);
		b->remove_book();
	}
	refresh();
	bookshelf1->print_content(false);
	bookshelf2->print_content(false);
}

void AppManager::find_books(){
	std::string keyword = inputwindow->input_book_name(1);
	bookshelf1->search_book(keyword);
	bookshelf2->search_book(keyword);
	getch();
	bookshelf1->recover_content();
	bookshelf2->recover_content();
}

bool AppManager::sort_books(){
	bool verify = true;
	Bookshelf* b = dwindow_choosing();
	if(b){
		if(!b->sort_books())
			verify = false;
	}
	refresh();
	bookshelf1->print_content(false);
	bookshelf2->print_content(false);

	return verify;
}

Bookshelf* AppManager::dwindow_choosing(){
	int dim_dwindow[2] = {10,30};
	DialogWindow* dialogwindow = new DialogWindow("Choose bookshelf:", dim_dwindow[0],dim_dwindow[1], scr_max_y/2 - dim_dwindow[0]/2, scr_max_x/2 - dim_dwindow[1]/2, 0);
	refresh();
	dialogwindow->print_content();
	
	Bookshelf* tmp_b = get_bookshelf(dialogwindow->choose());

	delwin(dialogwindow->get_window());
	delete dialogwindow;

	return tmp_b;
}

Bookshelf* AppManager::get_bookshelf(int b_num){
	std::vector<Bookshelf*> bss = {bookshelf1, bookshelf2};
	if(b_num == (int)bss.size())
		return NULL;
	return bss[b_num];
}

void AppManager::read_app_state(){
	std::vector<Bookshelf*> tmp_array = {bookshelf1, bookshelf2};
	std::vector<std::string> tmp_fnames = {"read.txt", "to_read.txt"};
	std::vector<std::string> tmp_content;

	std::ifstream file;

	for(int i=0; i<(int)tmp_fnames.size(); i++){
		file.open(tmp_fnames[i], std::ios::in);

		for(std::string line; getline(file, line); ){
			tmp_content.push_back(line);
		}
		
		tmp_array[i]->load_content(tmp_content);
		tmp_content.clear();
		file.close();
		tmp_array[i]->print_content(false);
	}
}

int AppManager::will_save(){
	int saving = 0;
	int dim_dwindow[2] = {10,30};
	DialogWindow* dialogwindow = new DialogWindow("Save changes?", dim_dwindow[0],dim_dwindow[1], scr_max_y/2 - dim_dwindow[0]/2, scr_max_x/2 - dim_dwindow[1]/2, 1);
	refresh();
	dialogwindow->print_content();

	saving = dialogwindow->choose();

	delwin(dialogwindow->get_window());
	delete dialogwindow;
	refresh();
	bookshelf1->print_content(false);
	bookshelf2->print_content(false);

	return saving;
}

void AppManager::save_app_state(){
	std::vector<Bookshelf*> tmp_array = {bookshelf1, bookshelf2}; 
	std::vector<std::string> tmp_fnames = {"read.txt", "to_read.txt"};

	std::ofstream file;
	
	for(int i=0; i<(int)tmp_fnames.size(); i++){
		file.open(tmp_fnames[i], std::ios::trunc);
		for(int j = 0; j<(int)tmp_array[i]->get_content().size(); j++){
			file << ((tmp_array[i]->get_content())[j]+"\n");
		}
		file.close();
	}
}

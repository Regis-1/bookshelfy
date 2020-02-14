#include "../include/Bookshelf.hh"

Bookshelf::Bookshelf(std::string t, int size_y, int size_x, int y, int x){
	title = t;
	new_iwindow(size_y, size_x, y, x);
	refresh();
	box_window();
	add_window_title(title);
	irefresh();
}

int Bookshelf::print_content(){
	return 0;
}

int Bookshelf::input_action(){
	return 0;
}

#include "../include/Bookshelf.hh"

Bookshelf::Bookshelf(std::string t, int size_y, int size_x, int y, int x){
	title = t;
	new_iwindow(size_y, size_x, y, x);
	refresh();
	box_window();
	add_window_title(title);
	irefresh();
}

void Bookshelf::add_book(std::string bn){
	std::vector<std::string> tmp = get_content();
	tmp.push_back(bn);
	load_content(tmp);
}

void Bookshelf::update(){
	print_content();
}

void Bookshelf::print_content(){
	std::vector<std::string> tmp_content = get_content();
	std::vector<int> wmax = get_max_dimensions();

	iclear_window();
	box_window();
	add_window_title(title);
	irefresh();

	for(int i=0; i<(int)get_content().size(); i++){
		mvwprintw(get_window(), 1+i, 1, tmp_content[i].c_str());
	}
	irefresh();
}

int Bookshelf::input_action(){
	return 0;
}

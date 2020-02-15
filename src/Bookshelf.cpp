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

void Bookshelf::remove_book(){
	int book_num = select_book();
	std::vector<std::string> tmp = get_content();
	tmp.erase(tmp.begin() + book_num);
	load_content(tmp);
	set_highlighted(0);
}

int Bookshelf::select_book(){
	int book_num = -1;
	while(book_num < 0){
		print_content(true);
		book_num = input_action(); //TODO: pressing ESC to cancel selecting
	}
	return book_num;
}

void Bookshelf::print_content(bool w_highlight){
	std::vector<std::string> tmp_content = get_content();
	std::vector<int> wmax = get_max_dimensions();

	iclear_window();
	box_window();
	add_window_title(title);

	if(w_highlight){
		for(int i=0; i<(int)get_content().size(); i++){
			if(i == get_highlighted())
				iwattron(A_REVERSE);
			std::string record = std::string(std::to_string(i+1)) + ". " + tmp_content[i];
			mvwprintw(get_window(), 1+i, 1, record.c_str());
			iwattroff(A_REVERSE);
		}
	}
	else{
		for(int i=0; i<(int)get_content().size(); i++){
			std::string record = std::string(std::to_string(i+1)) + ". " + tmp_content[i];
			mvwprintw(get_window(), 1+i, 1, record.c_str());
		}
	}
	irefresh();
}

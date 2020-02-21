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
	if(book_num > 0){
		std::vector<std::string> tmp = get_content();
		tmp.erase(tmp.begin() + book_num);
		load_content(tmp);
		set_highlighted(0);
	}
}

void Bookshelf::search_book(std::string keyword){
	std::vector<std::string> tmp_content = get_content();
	stash = tmp_content;
	std::vector<std::string> searched_books;
	size_t found;

	for(int i=0; i<(int)tmp_content.size(); i++){
		found = tmp_content[i].find(keyword);
		if(found != std::string::npos)
			searched_books.push_back(tmp_content[i]);
	}

	load_content(searched_books);
	print_content(false);
}

bool Bookshelf::sort_books(){
	std::vector<std::string> tmp_content = get_content();
	if(tmp_content.empty())
		return false;
	else
		std::sort(tmp_content.begin(), tmp_content.end());

	load_content(tmp_content);
	return true;
}

int Bookshelf::select_book(){
	int book_num = -1;
	while(book_num < 0){
		print_content(true);
		book_num = input_action();
		if(book_num == -2)
			break;
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

void Bookshelf::recover_content(){
	load_content(stash);
	stash.clear();
	print_content(false);
}

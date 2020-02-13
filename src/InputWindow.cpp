#include "../include/InputWindow.hh"

InputWindow::InputWindow(int size_y, int size_x, int y, int x){
	load_content(menu);

	new_iwindow(size_y, size_x, y, x);
	refresh();
	box_window();
	irefresh();
}

int InputWindow::print_content(){
	std::vector<std::string> tmp_content = get_content();
	int options_size = get_content_size();
	std::vector<int> wmax = get_max_dimensions();
	long unsigned int option_space = wmax[1]/options_size;

	for(int i=0; i<options_size; i++)
		if(tmp_content[i].length() >= option_space)
			return -1;

	for(int i=0; i<options_size; i++){
		if(i == get_highlighted())
			iwattron(A_REVERSE);
		mvwprintw(get_window(), 1, ((option_space/2 - tmp_content[i].length()) + option_space*i), tmp_content[i].c_str());
		iwattroff(A_REVERSE);
		irefresh();
	}
	return 0;
}

int InputWindow::input_action(){
	int ch = 0;
	ch = getch();
	switch(ch){
		case KEY_LEFT:
			sub_highlighted();
			if(get_highlighted() < 0)
				set_highlighted(0);
			break;
		case KEY_RIGHT:
			add_highlighted();
			if(get_highlighted() > get_content_size()-1)
				set_highlighted(get_content_size()-1);
			break;
		case K_ENTER:
			return get_highlighted();
	}
	return -1;
}

#include "../include/InputWindow.hh"

InputWindow::InputWindow(int size_y, int size_x, int y, int x){
	load_content(menu);

	new_iwindow(size_y, size_x, y, x);
	refresh();
}

int InputWindow::print_content(){
	std::vector<std::string> tmp_content = get_content();
	std::vector<int> wmax = get_max_dimensions();
	long unsigned int option_space = wmax[1]/get_content().size();

	iclear_window();
	box_window();
	irefresh();

	for(int i=0; i<(int)get_content().size(); i++)
		if(tmp_content[i].length() >= option_space)
			return -1;

	for(int i=0; i<(int)get_content().size(); i++){
		if(i == get_highlighted())
			iwattron(A_REVERSE);
		mvwprintw(get_window(), 1, ((option_space/2 - tmp_content[i].length()) + option_space*i), tmp_content[i].c_str());
		iwattroff(A_REVERSE);
	}
	irefresh();
	return 0;
}

std::string InputWindow::input_book_name(int prompt_num){
	iclear_window();
	box_window();
	irefresh();

	echo();
	curs_set(1);
	std::string s = input_prompt(prompt_num);
	noecho();
	curs_set(0);

	print_content();

	return s;
}

std::string InputWindow::input_prompt(int prompt_num){
	char buffer[512];
	mvwprintw(get_window(), 1, 1, prompts[prompt_num].c_str());	
	wgetstr(get_window(), buffer);
	return std::string(buffer);
}

bool InputWindow::menu_loop(int* choice){
	while(*choice < 0){
		if(print_content() != 0){
			endwin();
			return true;
		}
		*choice = input_action();
	}
	return false;
}

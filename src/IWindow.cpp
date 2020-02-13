#include "../include/IWindow.hh"

void IWindow::new_iwindow(int size_y, int size_x, int y, int x){
	window = newwin(size_y, size_x, y, x);
	getmaxyx(window, max_y, max_x);
}

std::vector<int> IWindow::get_max_dimensions(){
	std::vector<int> tmp = {max_y, max_x};
	return tmp;
}

void IWindow::box_window(){
	box(window,0,0);
}

void IWindow::print_content(){
}

void IWindow::irefresh(){
	wrefresh(window);
}

void IWindow::add_window_title(std::string title){
	mvwprintw(window, 0, max_x/2 - (title.length()/2), title.c_str());
}

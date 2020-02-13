#include "../include/IWindow.hh"

void IWindow::new_iwindow(int size_y, int size_x, int y, int x){
	window = newwin(size_y, size_x, y, x);
	getmaxyx(window, max_y, max_x);
}

WINDOW* IWindow::get_window(){
	return window;
}

void IWindow::iwattron(int attrs){
	wattron(window, attrs);
}

void IWindow::iwattroff(int attrs){
	wattroff(window, attrs);
}

std::vector<int> IWindow::get_max_dimensions(){
	std::vector<int> tmp = {max_y, max_x};
	return tmp;
}

void IWindow::box_window(){
	box(window,0,0);
}

void IWindow::load_content(std::vector<std::string> c){
	content.swap(c);
}

void IWindow::push_content(std::string s){
	content.push_back(s);
}

void IWindow::pop_content(){
	content.pop_back();
}

std::vector<std::string> IWindow::get_content(){
	return content;
}

int IWindow::get_content_size(){
	return content.size();
}

void IWindow::irefresh(){
	wrefresh(window);
}

void IWindow::add_window_title(std::string title){
	mvwprintw(window, 0, max_x/2 - (title.length()/2), title.c_str());
}

int IWindow::get_highlighted(){
	return highlighted;
}

void IWindow::set_highlighted(int n){
	highlighted = n;
}

void IWindow::add_highlighted(){
	highlighted++;
}

void IWindow::sub_highlighted(){
	highlighted--;
}

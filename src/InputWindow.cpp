#include "../include/InputWindow.hh"

InputWindow::InputWindow(int size_y, int size_x, int y, int x){
	new_iwindow(size_y, size_x, y, x);
	refresh();
	box_window();
	irefresh();
}

#ifndef IWINDOW_HH_
#define IWINDOW_HH_

#include <ncurses.h>
#include <string>
#include <vector>

class IWindow{
	private:
		WINDOW* window;
		std::vector<std::string> content;
		int max_y, max_x;
	public:
		void new_iwindow(int size_y, int size_x, int y, int x);
		std::vector<int> get_max_dimensions();
		void box_window();
		void print_content();
		void irefresh();
		void add_window_title(std::string title);
};

#endif

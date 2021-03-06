#ifndef IWINDOW_HH_
#define IWINDOW_HH_

#include <ncurses.h>
#include <string>
#include <vector>

#define K_ENTER 10

class IWindow{
	private:
		WINDOW* window;
		std::vector<std::string> content;
		int max_y, max_x;
		int highlighted = 0;
	public:
		void new_iwindow(int size_y, int size_x, int y, int x);
		WINDOW* get_window();
		void iwattron(int attrs);
		void iwattroff(int attrs);
		std::vector<int> get_max_dimensions();
		void box_window();
		void iclear_window();
		void load_content(std::vector<std::string> c);
		void push_content(std::string s);
		void pop_content();
		std::vector<std::string> get_content();
		void irefresh();
		void add_window_title(std::string title);
		int get_highlighted();
		void set_highlighted(int n);
		void add_highlighted();
		void sub_highlighted();
		int input_action();
};

#endif

#ifndef BOOKSHELF_HH_
#define BOOKSHELF_HH_

#include <ncurses.h>
#include <string>

#include "../include/IWindow.hh"

class Bookshelf : public IWindow{
	private:
		std::string title;
	public:
		Bookshelf(std::string t, int size_y, int size_x, int y, int x);
		void add_book(std::string bn);
		void update();
		void print_content();
		int input_action();
};

#endif

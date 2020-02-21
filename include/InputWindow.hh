#ifndef INPUTWINDOW_HH_
#define INPUTWINDOW_HH_

#include "../include/IWindow.hh"

class InputWindow : public IWindow{
	private:
		std::vector<std::string> menu = {"Add new book", "Remove book", "Find", "Sort", "Exit"};
		std::vector<std::string> prompts = {"Name of the book: ", "Keyword to find: "};
	public:
		InputWindow(int size_y, int size_x, int y, int x);
		int print_content();
		std::string input_book_name(int prompt_num);
		std::string input_prompt(int prompt_num);
		bool menu_loop(int* choice);
};

#endif

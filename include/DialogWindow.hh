#ifndef DIALOGWINDOW_HH_
#define DIALOGWINDOW_HH_

#include "../include/IWindow.hh"

class DialogWindow : public IWindow{
	private:
		std::string title;
		std::vector<std::string> options_bookshelf = {"Read", "To read", "Back"};
		std::vector<std::string> options_yes_no = {"Yes", "No", "Back"};
	public:
		DialogWindow(std::string t, int size_y, int size_x, int y, int x, int options_set);
		int print_content();
		int choose();
};

#endif

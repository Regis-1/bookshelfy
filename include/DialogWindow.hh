#ifndef DIALOGWINDOW_HH_
#define DIALOGWINDOW_HH_

#include "../include/IWindow.hh"

class DialogWindow : public IWindow{
	private:
		std::string title;
		std::vector<std::string> options = {"Read", "To read", "Back"};
	public:
		DialogWindow(std::string t, int size_y, int size_x, int y, int x);
		int print_content();
		int choose_bookshelf();
};

#endif

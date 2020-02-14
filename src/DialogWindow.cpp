#include "../include/DialogWindow.hh"

DialogWindow::DialogWindow(std::string t, int size_y, int size_x, int y, int x){
	load_content(options);
	title = t;

	new_iwindow(size_y, size_x, y, x);
	refresh();
}

int DialogWindow::print_content(){
	std::vector<std::string> tmp_content = get_content();
	std::vector<int> wmax = get_max_dimensions();

	iclear_window();
	box_window();
	irefresh();

	mvwprintw(get_window(), wmax[0]/2 - (get_content().size()+2)/2, wmax[1]/2 - title.length()/2, title.c_str());
	for(int i=0; i<(int)get_content().size(); i++){
		if(i == get_highlighted())
			iwattron(A_REVERSE);
		mvwprintw(get_window(), wmax[0]/2 - (get_content().size())/2 + i, wmax[1]/2 - tmp_content[i].length()/2, tmp_content[i].c_str());
		iwattroff(A_REVERSE);
	}
	irefresh();
	return 0;
}

int DialogWindow::input_action(){
	return 0;
}

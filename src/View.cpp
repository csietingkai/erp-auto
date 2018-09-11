#include <iostream>

#include "View.h"

using namespace std;
using namespace Gtk;

// constructors
View::View()
{
	set_title(WINDOW_TITLE);
	set_size_request(WINDOW_WIDTH, WINDOW_HEIGHT); 
	
	add(frm_all);
	frm_all.add(vbox_all);
	vbox_all.set_orientation(ORIENTATION_VERTICAL);
	
	vbox_all.pack_start(hbox_fileselector);
	hbox_fileselector.pack_start(ety_filename);
	hbox_fileselector.pack_start(btn_choose_file);
	
	vbox_all.pack_start(hbox_btngroup);
	hbox_btngroup.pack_start(btnbox_start_and_close);
	btnbox_start_and_close.pack_start(btn_start);
	btn_start.set_label("start");
	btnbox_start_and_close.pack_start(btn_close);
	btn_close.set_label("close");
	
	show_all_children();
}

View::~View()
{
}

// protected functions


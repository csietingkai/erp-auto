#include <iostream>
#include <fstream>

#include "View.h"
#include "FileData.h"

using namespace std;
using namespace Gtk;
using namespace Glib;

// constructors
View::View()
{
	init();
	show_all_children();
}

View::~View()
{
}

// protected functions
void View::init()
{
	set_title(WINDOW_TITLE);
	set_size_request(WINDOW_WIDTH, WINDOW_HEIGHT); 
	set_border_width(CONTAINER_BORDER_SIZE);
	set_position();
	set_attribute();
	set_signal_handler();
}

void View::set_position()
{
	add(vbox_all);
	vbox_all.pack_start(sbox1);
	vbox_all.pack_start(hbox_fileselector);
		hbox_fileselector.pack_start(ety_filename);
		hbox_fileselector.pack_start(btn_select_file);
	vbox_all.pack_start(sbox2);
	vbox_all.pack_start(hbox_btngroup);
		hbox_btngroup.pack_start(btnbox_start_and_close);
		btnbox_start_and_close.pack_start(btn_start, Gtk::PACK_SHRINK);
		btnbox_start_and_close.pack_start(btn_close, Gtk::PACK_SHRINK);
}

void View::set_attribute()
{
	vbox_all.set_orientation(ORIENTATION_VERTICAL);
	
	sbox1.set_border_width(SPACING_BORDER_SIZE);
	
	ety_filename.set_sensitive(false);
	ety_filename.set_text(filename);
	
	btn_select_file.set_label(STR_SELECT_FILE);
	
	sbox2.set_border_width(SPACING_BORDER_SIZE);
	
	btnbox_start_and_close.set_spacing(BUTTON_SPACING_SIZE);
	btnbox_start_and_close.set_layout(Gtk::BUTTONBOX_END);
	
	btn_start.set_label(STR_START);
	
	btn_close.set_label(STR_CLOSE);
}

void View::set_signal_handler()
{
	btn_select_file.signal_clicked().connect([&]()
	{
		on_btn_select_click();
	});
	
	btn_start.signal_clicked().connect([&]()
	{
		on_btn_start_click();
	});
	
	btn_close.signal_clicked().connect([&]()
	{
		on_btn_close_click();
	});
}

// private functions
void View::on_btn_select_click()
{
	FileChooserDialog dialog("Please choose a file", Gtk::FILE_CHOOSER_ACTION_OPEN);
	dialog.set_transient_for(*this);
	
	// Add response buttons the the dialog:
	dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
	dialog.add_button("_Open", Gtk::RESPONSE_OK);

	// Add filters, so that only certain file types can be selected:
	RefPtr<FileFilter> filter_excel = FileFilter::create();
	filter_excel->set_name("Excel files");
	filter_excel->add_mime_type("application/vnd.openxmlformats-officedocument.spreadsheetml.sheet"); // .xlsx
	filter_excel->add_mime_type("application/vnd.ms-excel"); // .xls
	//dialog.add_filter(filter_excel);
	
	RefPtr<FileFilter> filter_csv = FileFilter::create();
	filter_csv->set_name("CSV files");
	filter_csv->add_mime_type("text/csv"); // .csv
	dialog.add_filter(filter_csv);
	
	int result = dialog.run();
	
	switch(result)
	{
		case Gtk::RESPONSE_OK:
			file_full_path = dialog.get_filename();
			filename = basename(dialog.get_filename().c_str());
			set_filename(filename);
			break;
		case Gtk::RESPONSE_CANCEL:
			break;
		default:
			break;
	}
}

void View::on_btn_start_click()
{
	cout << file_full_path << endl;
	if(!file_full_path.empty())
	{
		// minimize the window
		//iconify();
		
		FileData data(file_full_path);
	}
}

void View::on_btn_close_click()
{
	close();
}

void View::set_filename(const string name)
{
	// show the select file name
	ety_filename.set_text(name);
}

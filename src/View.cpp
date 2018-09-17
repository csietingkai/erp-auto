#include <iostream>

#include "View.h"

using namespace std;
using namespace Gtk;

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
	
	btn_select_file.set_label(SELECT_FILE);
	
	sbox2.set_border_width(SPACING_BORDER_SIZE);
	
	btnbox_start_and_close.set_spacing(BUTTON_SPACING_SIZE);
	btnbox_start_and_close.set_layout(Gtk::BUTTONBOX_END);
	
	btn_start.set_label(START);
	
	btn_close.set_label(CLOSE);
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

void View::set_filename(const string name)
{
	ety_filename.set_text(name);
}

// private functions
void View::on_btn_select_click()
{
	cout << "select file" << endl;
	
	FileChooserDialog dialog("Please choose a file", Gtk::FILE_CHOOSER_ACTION_OPEN);
	dialog.set_transient_for(*this);

  //Add response buttons the the dialog:
  dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
  dialog.add_button("_Open", Gtk::RESPONSE_OK);

  //Add filters, so that only certain file types can be selected:

  auto filter_text = Gtk::FileFilter::create();
  filter_text->set_name("Text files");
  filter_text->add_mime_type("text/plain");
  dialog.add_filter(filter_text);

  auto filter_cpp = Gtk::FileFilter::create();
  filter_cpp->set_name("C/C++ files");
  filter_cpp->add_mime_type("text/x-c");
  filter_cpp->add_mime_type("text/x-c++");
  filter_cpp->add_mime_type("text/x-c-header");
  dialog.add_filter(filter_cpp);

  auto filter_any = Gtk::FileFilter::create();
  filter_any->set_name("Any files");
  filter_any->add_pattern("*");
  dialog.add_filter(filter_any);

  //Show the dialog and wait for a user response:
  int result = dialog.run();

  //Handle the response:
  switch(result)
  {
    case(Gtk::RESPONSE_OK):
    {
      std::cout << "Open clicked." << std::endl;

      //Notice that this is a std::string, not a Glib::ustring.
      std::string filename = dialog.get_filename();
      std::cout << "File selected: " <<  filename << std::endl;
      break;
    }
    case(Gtk::RESPONSE_CANCEL):
    {
      std::cout << "Cancel clicked." << std::endl;
      break;
    }
    default:
    {
      std::cout << "Unexpected button clicked." << std::endl;
      break;
    }
  }
}

void View::on_btn_start_click()
{
	cout << "start" << endl;
}

void View::on_btn_close_click()
{
	hide();
}

#ifndef VIEW_H_
#define VIEW_H_

#include <gtkmm.h>

using namespace std;
using namespace Gtk;

class View : public Gtk::Window
{
	public:
		View();
		virtual ~View();
		
	protected:
		Frame frm_all;
		Box vbox_all;
		
		Box hbox_fileselector;
		Entry ety_filename;
		Button btn_choose_file;
		
		Box hbox_btngroup;
		ButtonBox btnbox_start_and_close;
		Button btn_start;
		Button btn_close;
	
	private:
		const string WINDOW_TITLE = "SmartERP Auto Action";
		const int WINDOW_WIDTH = 400;
		const int WINDOW_HEIGHT = 200;
};

#endif // VIEW_H_

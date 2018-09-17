#ifndef VIEW_H_
#define VIEW_H_

#include <gtkmm.h>

using namespace std;
using namespace Gtk;

class View : public Window
{
	public:
		View();
		virtual ~View();
		
	protected:
		void init();
		void set_position();
		void set_attribute();
		void set_signal_handler();
		
		void set_filename(const string name);
		
		Box vbox_all;
		
		Box sbox1;			// box for spacing
		
		Box hbox_fileselector;
		Entry ety_filename;
		Button btn_select_file;
		
		Box sbox2;			// box for spacing
		
		Box hbox_btngroup;
		ButtonBox btnbox_start_and_close;
		Button btn_start;
		Button btn_close;
	
	private:
		void on_btn_select_click();
		void on_btn_start_click();
		void on_btn_close_click();
		
		string filename = "selct a xlsx file";
		
		const string WINDOW_TITLE = "SmartERP Auto Action";
		const int WINDOW_WIDTH = 350;
		const int WINDOW_HEIGHT = 150;
		
		const int CONTAINER_BORDER_SIZE = 20;
		const int SPACING_BORDER_SIZE = 10;
		const int BUTTON_SPACING_SIZE = 5;
		const string SELECT_FILE = "select file";
		const string START = "start";
		const string CLOSE = "close";
};

#endif // VIEW_H_

#ifndef HELLO_WORLD_H_
#define HELLO_WORLD_H_

#include <gtkmm/button.h>
#include <gtkmm/window.h>

class HelloWorld : public Gtk::Window
{
	public:
		HelloWorld();
		virtual ~HelloWorld();
		
	protected:
		Gtk::Button button;
		
		void on_button_clicked();		// signal handler
};

#endif // HELLO_WORLD_H_

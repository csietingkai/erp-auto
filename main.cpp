#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <gtkmm/application.h>

#include "src/helloworld.h"
#include "src/ExampleWindow.h"
#include "src/View.h"

using namespace std;

int main(int argc, char* argv[])
{
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv);
	
	View window;
	
	return app->run(window);
}

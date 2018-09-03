#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <gtkmm.h>

using namespace std;
using namespace Glib;
using namespace Gtk;

int main(int argc, char* argv[])
{
	RefPtr<Application> app = Application::create(argc, argv);
	
	Window window;
	window.set_default_size(200, 200);
	
	return app->run(window);
}

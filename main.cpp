#include <cstdio>
#include <cstdlib>
#include <gtkmm.h>
#include <iostream>
#include <string>

#include "src/View.h"

using namespace std;
using namespace Gtk;
using namespace Glib;

int main(int argc, char* argv[])
{
	RefPtr<Application> app = Application::create(argc, argv);
	
	View window;
	
	return app->run(window);
}

#include <iostream>

#include "helloworld.h"

using namespace std;

// constructors
HelloWorld::HelloWorld()
: button("button text")
{
	set_border_width(10);
	button.signal_clicked().connect(sigc::mem_fun(*this, &HelloWorld::on_button_clicked));
	add(button);
	button.show();
}

HelloWorld::~HelloWorld()
{
}

// protected functions
void HelloWorld::on_button_clicked()
{
	cout << "Hello World" << endl;
}

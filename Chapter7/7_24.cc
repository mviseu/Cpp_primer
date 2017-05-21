#include <iostream>
#include "7_24_Screen.h"

using std::cout;
using std::endl;


int main() {
	//using constructors
	Screen Sdefault = Screen();
	Screen Sblank(24, 80);
	Screen Schar(44, 160, 'c');
	//using get member functions
	cout << Sblank.get() << endl;;
	cout << Schar.get(4,5) << endl;
	Sblank.move(20, 40);

	return 0;
}
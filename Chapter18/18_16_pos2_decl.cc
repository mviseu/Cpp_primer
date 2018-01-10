#include <iostream>

namespace Exercise {
	int ivar = 1;
	double dvar = 0;
	const int limit = 1000;
}

int ivar = 0;

void manip() {
	// position 2
	using Exercise::ivar; 
	using Exercise::dvar;
	using Exercise::limit;

	//double dvar = 3.1416;  // error since dvar has already been defined in Exercise::dvar
	int iobj = limit + 1; // uses Exercise::limit
	std::cout << "++ivar " << ++ivar << std::endl; // uses Exercise::ivar
	std::cout << "++::ivar " << ++::ivar << std::endl; // Uses global scope ivar
}

int main() {
	manip();
	return 0;
}

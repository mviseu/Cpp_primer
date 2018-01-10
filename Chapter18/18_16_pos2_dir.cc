#include <iostream>

namespace Exercise {
	int ivar = 1;
	double dvar = 0;
	const int limit = 1000;
}

int ivar = 0;

void manip() {
	// position 2
	using namespace Exercise; // names from Exercise are now accessible from the global scope

	double dvar = 3.1416; // hides Exercise::dvar
	int iobj = limit + 1; // uses Exercise::limit
	//std::cout << "++ivar " << ++ivar << std::endl; // ambiguous
	std::cout << "++::ivar " << ++::ivar << std::endl; // Uses global scope ivar
}

int main() {
	manip();
	return 0;
}

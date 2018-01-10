#include <iostream>

namespace Exercise {
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}

int ivar = 1;

// position 1
using namespace Exercise; // makes all names in Exercise accessible from global scope -> ok as long as ivar is called unambiguously


void manip() {
	double dvar = 3.1416; // hides Exercise::dvar
	int iobj = limit + 1; // uses Exercise::limit
	//++ivar; // error with ivar ambiguous
	std::cout << "++::ivar " << ++::ivar << std::endl; // ivar is 2
}

int main() {
	manip();
	return 0;
}

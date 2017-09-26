#include "14_24.h"
#include <iostream>

int main() {
	Book b1("Mormon");
	b1 = "Different title";
	std::cout << b1 << std::endl;
	return 0;
}

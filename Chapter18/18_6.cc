#include <iostream>

struct exceptionType {
	int i = 42;
};

void Throw() {
	exceptionType exc;
	throw &exc;
}

typedef int EXCPTYPE;

int main() {
	exceptionType exc;
	try {
		throw &exc;
	}	
	catch (exceptionType *pet) {
		std::cout << "handled " << pet->i << std::endl;
	}
	catch (...) {
		std::cout << "catches any exception" << std::endl;
	}


	try {
		throw EXCPTYPE(1);
	}

	catch (int) {
		std::cout << "catches typedef" << std::endl;
	}
	return 0;
}
#include <stdexcept>
#include <iostream>
#include <cstdlib>

int main() {
	try {
		throw std::bad_alloc();
	} catch (const std::exception &exc) {
		std::cout << exc.what() << std::endl;
		std::abort();
	}
	return 0;
}
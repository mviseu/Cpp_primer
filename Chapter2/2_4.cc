#include <iostream>

int main() {

	unsigned u = 10, u2 = 42;
	std::cout << u2 - u << std::endl;
	// "negative unsigned will wrap around"
	std::cout << u - u2 << std::endl;

	int v = 10, v2 = 42;
	std::cout << v - v2 << std::endl;
	std::cout << v2 - v << std::endl;

	std::cout << u - v << std::endl;
	std::cout << v - u << std::endl;
	return 0;
}
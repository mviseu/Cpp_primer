// Calling operators from the global scope
#include <string>
#include <iostream>

int main() {
	std::string hello_incomplete("Hell");
	std::cout << std::operator+(hello_incomplete, "o") << std::endl;
	return 0;
}
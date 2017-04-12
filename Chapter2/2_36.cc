#include <iostream>

int main() {

	int a = 3, b = 4;
	//c is the same type as a, i.e., an integer
	decltype(a) c = a;
	std::cout << c << std::endl;

	//d is a reference to an int and must be initialized
	decltype((b)) d = a;

	//a + 1 = 4
	++c;
	std::cout << "c at the end: " << c << std::endl;

	//changing the value of d and of a to 4
	++d;
	std::cout << "d at the end: " << d 
			  << "\na at the end: " << a << std::endl;
	return 0;
}
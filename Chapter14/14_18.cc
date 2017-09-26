#include "14_7_String.h"
#include <iostream>

int main() {
	String s1="goodbye", s2="Goodbye";
	std::cout << (s2 < s1) << std::endl;
	if(String("Hello") == String("Hello")) {
		std::cout << "Hello and Hello are equal" << std::endl;
	}
	if(String("Hello") != String("hello")) {
		std::cout << "Hello and hello are not equal" << std::endl;
	}
	if(String("Hello") >= String("Hello")) {
		std::cout << "Hello and Hello are >=" << std::endl;
	}
	if(String("Hello") >= String("Goodbye")) {
		std::cout << "Hello and Goodbye are >=" << std::endl;
	}
	if(String("Hello") > String("Goodbye")) {
		std::cout << "Hello and Goodbye are >" << std::endl;
	}
	if(String("Goodbye") <= String("Hello")) {
		std::cout << "Goodbye and Hello are <=" << std::endl;
	}
	if(String("Goodbye") <= String("Goodbye")) {
		std::cout << "Goodbye and Goodbye are <=" << std::endl;
	}
	return 0;
}

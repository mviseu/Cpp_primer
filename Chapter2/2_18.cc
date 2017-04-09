#include <iostream>

int main() {
	int v1 = 1, v2 = 2 ;
	//create pointer p1 that points to the object v1
	int *p1 = &v1;
	std::cout << "This is the address held by p1: "  << p1 << std::endl;
	std::cout << "This is the value of the object to which p1 points to: " 
			  << *p1 << std::endl;
	//Now p1 will hold the address of v2
	p1 = &v2;
	std::cout << "This is the address held by p1: "  << p1 << std::endl;
	std::cout << "This is the value of the object to which p1 points to: " 
			  << *p1 << std::endl;
	// Using dereference operator to change object v2
	*p1 = 3;
	std::cout << "This is the value of the object to which p1 points to " 
			  << *p1 << ", which is the same as " << v2 << std::endl;

	return 0;
}


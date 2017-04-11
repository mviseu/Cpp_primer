#include <iostream>
int main() {
	const int i = 42;

	//j is int since top level const in i is dropped
	auto j = i;
	//we can assign j 
	j = 43 ;
	//j is printed out as an int
	std::cout << j << std::endl;

	//const const int &
	//the auto (const int) becomes int
	const auto &k = i;
	
	//p is a pointer to a const int 
	//const int * p
	auto *p = &i;
	std::cout << &i << p << std::endl;
	// Changing i will not work: *p = 0 ;

	//auto will be int
	//j2 is of type const int
	//k2 is of type const int & (auto means int)
	const auto j2 = i, &k2 = i;
	//Assigning k2 will not work k2 = 0 ; 
	//Assigning j2 will also not work j2 = 0;

	return 0; 
}

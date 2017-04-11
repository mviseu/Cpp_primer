#include <iostream>

int main() {
	int i = 0, &r = i;
	//a is type int since r refers to an object of type int
	auto a = r;

	a = 42;
	std::cout << a << std::endl;
	
	//b is int since ci top-level in const (dropped)
	const int ci = i, &cr = ci; 
	auto b = ci;

	b = 42;
	std::cout << b << std::endl;

	//cr is alias for ci. ci top-level const is dropped -> c is int
	auto c = cr;
	c = 42;
	std::cout << c << std::endl;

	//&i is &int which means d is of type int*
	//a pointer holds an address/nullpointer
	//conversion from int (42) to int* is not possible 
	//d = 42; 
	auto d = &i;

	// top level ci constant is not dropped. e is const int* 
	// conversion from int (42) to constint* is not possible
	//e = 42;
	auto e = &ci ;

	// constint&
	//we cannot assign the type of a const int (read only)
	auto &g = ci; 
	//g = 42 ;

	return 0;
}
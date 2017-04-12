#include <iostream>

int main() {
	// How auto and decltype behave differently

	const int a = 0 ;
	//auto ignores top-level const
	auto b = a ;
	// b can be assigned
	b = 3 ;

	//decltype does NOT ignore top-level const
	decltype(a) c = 0 ;
	//c will be a read-only variable
	//c = 3 ;

	int d = 3, &r = d ;

	// auto is int not int& since r is an alias for d
	auto e = r ;
	e = 2 ;
	// e will be assigned the value of 2 but r/d will not change
	std::cout << "e: " << e << "\nr: " << r << std::endl;

	//decltype is int&
	decltype(r) f = r ;
	f = 2 ; 

	// The value of d and r will also have been changed to 2
	std::cout << "f: " << e << "\nr: " << r << std::endl;


	//auto and decltype deducing the same type
	const int g = 0 ;
	//h is const int
	const auto h = g ;
	//i is const int
	decltype(g) i = g ;
	return 0;
}
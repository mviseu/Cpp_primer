#include "16_16_Vec.h"
#include <iostream>
#include <iterator>
#include <memory>

int main() {
	std::ostream_iterator<std::string> os(std::cout, "\n");
	using StrVec = Vec<std::string>;
	StrVec vs1 = {"Hello", "new", "world"}, vs2 = vs1, vs3;
	if(vs1 == vs2) {
		os =  "vs1 and vs2 are equal";
	}
	if(vs2 != vs3) {
		os = "vs2 and vs3 are different";
	}
	if(vs1 <= vs2) {
		os = "vs1 is less or equal to vs2";
	}
	if(vs3 < vs2) {
		os = "vs3 is less than vs2";
	}
	if(vs2 > vs3) {
		os = "vs2 is more than vs3";
	}
	if(vs1 >= vs2) {
		os = "vs1 is greater or equal to vs2";
	}
	return 0;
}

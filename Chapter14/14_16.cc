#include "14_16_StrBlob.h"
#include "14_16_StrBlobPtr.h"
#include <iostream>
#include <iterator>
#include <memory>

int main() {
	std::ostream_iterator<std::string> os(std::cout, "\n");

	StrBlob v1({"Hello", "new", "world"}), v2, v3;

	v2 = v1;
	if(v2 == v2) {
		os =  "v1 and v2 are equal";
	}
	if(v2 != v3) {
		os = "v2 and v3 are different";
	}
	StrBlobPtr p1(v1, 1), p2(v2, 1), p3(v1, 0);
	if(p1 == p2) {
		os = "p1 and p2 are equal";
	}
	if(p2 != p3) {
		os = "p2 and p3 are different";
	}
	return 0;
}
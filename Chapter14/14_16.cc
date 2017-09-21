#include "14_16_StrBlob.h"
#include "14_16_StrBlobPtr.h"
#include "14_16_String.h"
#include "14_16_StrVec.h"
#include <iostream>
#include <iterator>
#include <memory>

int main() {
	std::ostream_iterator<std::string> os(std::cout, "\n");

	StrBlob v1({"Hello", "new", "world"}), v2, v3;
	StrBlobPtr p1(v1, 1), p2(v2, 1), p3(v1, 0);
	String s1 = "Hello", s2 = s1, s3 = "world";
	StrVec vs1 = {"Hello", "new", "world"}, vs2 = vs1, vs3;

	v2 = v1;
	if(v2 == v2) {
		os =  "v1 and v2 are equal";
	}
	if(v2 != v3) {
		os = "v2 and v3 are different";
	}
	if(p1 == p2) {
		os = "p1 and p2 are equal";
	}
	if(p2 != p3) {
		os = "p2 and p3 are different";
	}
	if(s1 == s2) {
		os = "s1 and s2 are equal";
	}
	if(s2 != s3) {
		os = "s2 and s3 are different";	
	}

	if(vs1 == vs2) {
		os =  "vs1 and vs2 are equal";
	}
	if(vs2 != vs3) {
		os = "vs2 and vs3 are different";
	}
	return 0;
}
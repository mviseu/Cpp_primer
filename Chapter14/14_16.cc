#include "14_16_StrBlob.h"
#include "14_16_StrBlobPtr.h"
#include "14_16_String.h"
#include "14_16_StrVec.h"
#include <iostream>
#include <iterator>
#include <memory>

int main() {
	std::ostream_iterator<std::string> os(std::cout, "\n");

	StrBlob v1({"Hello", "new", "world"}), v2 = {"new"}, v3 = v1;
	StrBlobPtr p1(v1, 0), p2(v2, 0), p3(v1, 0);
	String s1 = "Hello", s2 = s1, s3 = "world";
	StrVec vs1 = {"Hello", "new", "world"}, vs2 = vs1, vs3;

	if(v1 == v3) {
		os =  "v1 and v3 are equal";
	}
	if(v2 != v1) {
		os = "v2 and v1 are different";
	}
	if(v1 < v2) {
		os = "v1 is less than v2";
	}
	if(v2 > v1) {
		os = "v2 is greater than v1";
	}
	if(v1 <= v3) {
		os = "v1 is less or equal to v3";
	}
	if(v2 >= v1) {
		os = "v2 is greater or equal to v1";
	}
	if(p1 == p3) {
		os = "p1 and p3 are equal";
	}
	if(p1 != p2) {
		os = "p1 and p2 are different";
	}
	if(p1 >= p3) {
		os = "p1 is greater or equal to p3";
	}
	if(p1 <= p3) {
		os = "p1 is less or equal to p3";
	}
	if(p1 < p2) {
		os = "p1 is less than p2";
	}
	if(p2 > p1) {
		os = "p2 is more than p1";
	}
	std::cout << p1[0] << p1[1] << p1[2] << p1[3] << std::endl;

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

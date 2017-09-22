#include "14_16_StrVec.h"
#include "14_16_String.h"	
#include "14_16_StrBlob.h"
#include "14_16_StrBlobPtr.h"
#include <iostream>
#include <memory>

int main() {
	const StrVec svec1 = {"Hello", "new", "world"};
	StrVec svec2({"Hello", "new", "world"});
	svec2[1] = string("old");
	std::cout << svec2[1] << std::endl;
	std::cout << svec1[1] << std::endl;

	const String s1("Hello");
	String s2("Hello");
	s2[1] = 'a';
	std::cout << s2[1] << std::endl;
	std::cout << s1[1] << std::endl;

	const StrBlob sb1 = {"Hello", "new", "world"};
	StrBlob sb2({"Hello", "new", "world"});
	sb2[1] = string("old");
	std::cout << sb2[1] << std::endl;
	std::cout << sb1[1] << std::endl;

	StrBlobPtr sbp2(sb2, 0);
	return 0;
}
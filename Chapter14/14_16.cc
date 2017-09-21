#include "14_16_StrBlob.h"
#include <iostream>

int main() {
	StrBlob v1({"Hello", "new", "world"}), v2, v3;
	v2 = v1;
	if(v2 == v2) {
		std::cout << "v1 and v2 are equal" << std::endl;
	}
	if(v2 != v3) {
		std::cout << "v2 and v3 are different" << std::endl;
	}
	return 0;
}
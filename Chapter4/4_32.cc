#include <iostream>

using std::cout;
using std::endl;

int main() {

	constexpr int size = 5;
	int ia[size] = {1, 2, 3, 4, 5};

	//ptr starts pointing at first element of ia

	//This loop passes through the indexes (ix) of the array
	//The loop also passes a pointer through all the elements of the array
	//++ptr is not done to generate the off the end pointer
	for (int *ptr = ia, ix = 0; ix != size && ptr != ia + size;
		 ++ix, ++ptr) {
		//some code
	}

	return 0;
}
#include "16_6.h"
#include <iostream>

int main() {
	int arr[2] = {0, 1};
	for(auto i = ar::begin(arr); i != ar::end(arr); ++i) {
		std::cout << *i << std::endl;
	}
	return 0;
}

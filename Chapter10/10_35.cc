#include <vector>
#include <iostream>
#include <algorithm>


int main() {
	std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	if(!vec.empty()) {
		for(auto iter = vec.cend() - 1; iter >= vec.cbegin(); std::cout << *iter, --iter); 
	}

	return 0;
}
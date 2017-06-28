#include <vector>
#include <iostream>
#include <algorithm>


int main() {
	std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::for_each(vec.crbegin(), vec.crend(), [](const int i) {std::cout << i << " ";});
	return 0;
}
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

int main() {
	std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::list<int> ls;
	auto element_pos_seven = vec.crbegin() + 3;
	std::copy(element_pos_seven, element_pos_seven + 5, std::back_inserter(ls));
	for_each(ls.cbegin(), ls.cend(), [](int i) {std::cout << i << std::endl;});
	return 0;
}
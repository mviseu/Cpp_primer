#include <list>
#include <algorithm>
#include <iostream>


int main() {
	std::list<int> ls = {1, 0 , 3, 0, 5};
	auto last0 = find(ls.crbegin(), ls.crend(), 0);
	if(last0 != ls.crbegin()) {
		std::cout << *last0 << std::endl;
	}
	return 0;
}
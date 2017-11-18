#include <iostream>
#include <vector>
#include <iterator>

template <typename C> void f(const C &cont) {
	for(typename C::const_iterator it = std::begin(cont); it < std::end(cont); ++it) {
		std::cout << *it << std::endl;
	}
}


int main() {
	f(std::vector<int>({0, 2, 4, 6}));
	return 0;
}
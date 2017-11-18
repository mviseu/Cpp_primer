#include <iostream>
#include <vector>

template <typename C> void f(const C &cont) {
	for(typename C::size_type u = 0; u < cont.size(); ++u) {
		std::cout << cont[u] << std::endl;
	}
}


int main() {
	f(std::vector<int>({0, 2, 4, 6}));
	return 0;
}
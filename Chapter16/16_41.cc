#include <functional>
#include <iostream>


template <typename T1, typename T2> 
auto sum(T1 a, T2 b) -> decltype(a + b) {
	return a + b;
}

int main() {
	std::cout << sum(int(1), double(2.5)) << std::endl;
	return 0;
}

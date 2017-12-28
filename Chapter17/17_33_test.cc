#include <random>
#include <iostream>
#include <limits>

int main() {
	static std::default_random_engine e(std::numeric_limits<int>::max()/2 - 1);
	static std::uniform_int_distribution<int> d{0, 10000};
	for(auto i = 0; i < 20; ++i) {
		std::cout << d(e) << std::endl;
	}
	std::cout <<  d(e) << std::endl;
	return 0;
}
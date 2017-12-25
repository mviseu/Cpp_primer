#include <random>
#include <iostream>

unsigned random(unsigned min = 0, unsigned max = 10000, unigned seed = 0) {
	static std::default_random_engine e(seed);
	static std::uniform_int_distribution<unsigned> u(min, max);
	return u(e);
}

int main() {
	std::cout << random(5) << std::endl;
	std::cout << random() << std::endl;
	return 0;
}
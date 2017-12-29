
#include <cmath>
#include <iostream>

int main() {
	std::cout << std::fixed << 100 * std::sqrt(2) << std::endl;
	std::cout << std::scientific << 100 * std::sqrt(2) << std::endl;
	std::cout << std::hexfloat << std::uppercase << 100 * std::sqrt(2) << std::endl;
	std::cout << std::defaultfloat << std::nouppercase << 100 * std::sqrt(2) << std::endl;
	return 0;
}
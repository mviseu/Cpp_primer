#include <cmath>
#include <iostream>
#include <iomanip>

int main() {
	std::cout << std::setw(25) << std::fixed << 100 * std::sqrt(2) << std::endl;
	std::cout << std::setw(25) << std::scientific << 100 * std::sqrt(2) << std::endl;
	std::cout << std::setw(25) << std::hexfloat << std::uppercase << 100 * std::sqrt(2) << std::endl;
	std::cout << std::setw(25) << std::defaultfloat << std::nouppercase << 100 * std::sqrt(2) << std::endl;
	return 0;
}
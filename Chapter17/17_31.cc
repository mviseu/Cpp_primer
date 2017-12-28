#include <random>
#include <iostream>

int main() {
	std::default_random_engine e;
	std::bernoulli_distribution b;
	std::string resp;
	do {
		auto first = b(e);
		std::cout << (first ? "Program plays first" : "Player plays first") << std::endl;
		std::cout << "Play again? Enter 'yes' or 'no" << std::endl;

	} while (std::cin >> resp && resp[0] == 'y');
	return 0;
}
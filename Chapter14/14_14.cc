#include "Sales_data_14_14.h"
#include <iostream>

int main() {
	Sales_data S1("XX", 3, 2);
	Sales_data S2("XX", 2, 2);
	std::cout << (S1 += S2) << std::endl;
	std::cout << (S1 + S2) << std::endl;

	return 0;
}
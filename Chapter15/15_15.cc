#include "15_15_Disc_quote.h"
#include "15_5_Bulk_quote.h"
#include "15_7_Limit_quote.h"
#include <iostream>

int main() {
	Bulk_quote bqt("Hello", 2, 1, 0.5);
	Limit_quote lqt("Bye", 2, 1, 0.5);
	bqt.debug(std::cout);
	std::cout << std::endl;
	std::cout << bqt.net_price(2) << std::endl;
	lqt.debug(std::cout);
	std::cout << std::endl;
	std::cout << lqt.net_price(2) << std::endl;
	return 0;
}
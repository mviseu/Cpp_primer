#include <iostream>
#include "Sales_item.h"

int main() {
	//total will sum transactions of the same type
	Sales_item total;
	if (std::cin >> total) {
		//trans will hold each transaction
		Sales_item trans;
		while (std::cin >> trans) {
			if (trans.isbn() == total.isbn()) {
				total += trans;
			} else {
				std::cout << total << std::endl;
				total = trans;
			}
		}
		//print the last transaction
		std::cout << total << std::endl;

		return 0;

	} else {
		std::cerr << "Why are you not registering any transactions?? Are you a terrible salesman? :("
			      << std::endl;
		return -1;
	}
}
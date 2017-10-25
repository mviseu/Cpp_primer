#include "15_27_Bulk_quote.h"
#include "15_3_Quote.h"
#include <vector>
#include <memory>
#include <iostream>

int main() {
	std::vector<Quote> vec;
	//Keeps base parts (acts as base object, there is no derived to base conversion between objects, only ptrs)
	vec.push_back(Bulk_quote("Sliced Down", 2.0, 2, 0.5));
	std::cout << vec.front().net_price(4) << std::endl; //uses Quote virtual net_price

	//dynamic binding occurs when shared pointer
	std::vector<std::shared_ptr<Quote>> vec_ptr;
	vec_ptr.push_back(std::make_shared<Bulk_quote>("Sliced Down", 2.0, 2, 0.5));
	std::cout << vec_ptr.front()->net_price(4);
	return 0;
}
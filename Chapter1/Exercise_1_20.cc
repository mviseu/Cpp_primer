#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item books; 
	while (std::cin >> books) {
		std::cout << books << std::endl; 
	} 
	return 0;
}
#include <iostream>
#include "Sales_item.h"

int main() 
{
	Sales_item book1, book2;
	std::cin >> book1 >> book2; //read the two transactions
	std::cout << book1 + book2 << std::endl; //print the sum assuming equal ibsns
	return 0;
}
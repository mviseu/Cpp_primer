#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item book, book_sum;
	std::cin >> book_sum;
	while (std::cin >> book)
	{
		book_sum = book + book_sum;
	}
	std::cout << "The sum of all the transactions is " << book_sum << std::endl;
	return 0;
}



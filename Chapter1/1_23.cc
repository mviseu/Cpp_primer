#include <iostream>
#include "Sales_item.h"

int main() {

	Sales_item book_old, book_new;
	// We will assume that the records for each ISBN are grouped together in the input
	// We will also assume that there is at least one transaction
	std::cin >> book_old;
	int counter = 1;
	while (std::cin >> book_new) {
		if (book_new.isbn() == book_old.isbn()) {
			++counter;
		} else {
			std::cout << "There are " << counter 
				      << " transactions with ISBN " << book_old.isbn() << std::endl;
			counter = 1;
			book_old = book_new;
		} 
	}
	//Missing the last type of transactions
	std::cout << "There are " << counter << " transactions with ISBN " 
		      << book_old.isbn() << std::endl;

	return 0;
}
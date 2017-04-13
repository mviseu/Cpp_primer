#include <iostream>

struct Sales_data
{
	std::string isbn ;
	unsigned nr_units = 0 ;
	double revenue = 0.0 ;
};

int main() {
	Sales_data itemStart, item;

	double pricePerUnit = 1.; 

	unsigned counter = 1;

	// Read the 1st transaction
	std::cin >> itemStart.isbn >> itemStart.nr_units >> pricePerUnit ;

	// Assume transactions with the same ISBN are grouped together
	while(std::cin >> item.isbn >> item.nr_units 
					>> pricePerUnit) {

		if (itemStart.isbn == item.isbn) {
			++counter ;

		} else {
			std::cout << itemStart.isbn << " counts: " 
					  << counter << std::endl;
			counter = 1;
			itemStart.isbn = item.isbn ;
		}
	}  //end While

	//print the last count
	std::cout << itemStart.isbn << " counts: " 
			  << counter << std::endl;

	return 0;

}
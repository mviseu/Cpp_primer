#include <iostream>

struct Sales_data
{
	std::string isbn ;
	unsigned nr_units = 0 ;
	double revenue = 0.0 ;
};

int main() {

	double sales_price_per_book = 0.0 ;
	Sales_data transaction ;

	while (std::cin >> transaction.isbn >> 
		   transaction.nr_units >> sales_price_per_book) {

		std::cout << transaction.isbn << " "
				  << transaction.nr_units << " "
				  << sales_price_per_book << std::endl ;

	} 
	return 0 ;
}
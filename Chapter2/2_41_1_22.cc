#include <iostream>

struct Sales_data
{
	std::string isbn ;
	unsigned nr_units = 0 ;
	double revenue = 0.0 ;
};

int main() {
	Sales_data itemNext, item3 ;

	double pricePerUnitNext = 1., pricePerUnitFinal = 1., totalRevenue = 0 ; 

	unsigned totalItemsSold = 0 ;

	while(std::cin >> itemNext.isbn >> itemNext.nr_units 
					>> pricePerUnitNext) {

		totalItemsSold += itemNext.nr_units ;
		totalRevenue += pricePerUnitNext * itemNext.nr_units ;
	} 

	if (totalItemsSold != 0) {
		item3.isbn = itemNext.isbn ;
		item3.nr_units = totalItemsSold ;
		item3.revenue = totalRevenue ;
		pricePerUnitFinal = totalRevenue / totalItemsSold ;
		std::cout << item3.isbn << " " 
				  << item3.nr_units << " "
				  << item3.revenue << " "
				  << pricePerUnitFinal << std::endl ;

	} else {
		std::cout << "No data!" << std::endl ;
	}

	return 0;

}
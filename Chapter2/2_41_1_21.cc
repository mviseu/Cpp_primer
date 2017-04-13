#include <iostream>

struct Sales_data
{
	std::string isbn ;
	unsigned nr_units = 0 ;
	double revenue = 0.0 ;
};

int main() {
	Sales_data item1, item2, item3 ;
	double pricePerUnit1, pricePerUnit2, pricePerUnit3, totalRevenue ; 
	unsigned totalItemsSold ;

	//read the first transaction
	std::cin >> item1.isbn >> item1.nr_units >> pricePerUnit1 ;

	//read the second transaction (assume same isbn)
	std::cin >> item2.isbn >>item2.nr_units >> pricePerUnit2 ;

	totalItemsSold = item1.nr_units + item2.nr_units ;
	totalRevenue = item1.nr_units * pricePerUnit1 +
				   item2.nr_units * pricePerUnit2 ;

	if (totalItemsSold != 0) {
		item3.isbn = item1.isbn ;
		item3.nr_units = totalItemsSold ;
		item3.revenue = totalRevenue ;
		pricePerUnit3 = totalRevenue / totalItemsSold ;
		std::cout << item3.isbn << " " 
				  << item3.nr_units << " "
				  << item3.revenue << " "
				  << pricePerUnit3 << std::endl ;

	} else {
		std::cout << "No data!" << std::endl ;
	}

	return 0;

}
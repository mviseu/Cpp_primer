#include <iostream>

struct Sales_data
{
	std::string isbn ;
	unsigned nr_units = 0 ;
	double revenue = 0.0 ;
};

int main() {
	Sales_data itemStart, item;

	double pricePerUnitIn = 1., pricePerUnitOut = 1., totalRevenue = 0.0; 	
	unsigned counter = 0;

	//add an IF statement to ensure there is data to read
	if(std::cin >> itemStart.isbn >> itemStart.nr_units 
			    >> pricePerUnitIn) {
		totalRevenue = itemStart.nr_units * pricePerUnitIn ;
		counter = itemStart.nr_units;
		// Assume transactions with the same ISBN are grouped together
		while(std::cin >> item.isbn >> item.nr_units 
						>> pricePerUnitIn) {

			if (itemStart.isbn == item.isbn) {
				//start the counter and revenue
				counter += item.nr_units;
				totalRevenue += item.nr_units * pricePerUnitIn ;

			} else {
				pricePerUnitOut = totalRevenue / counter ;
				std::cout << itemStart.isbn << " " 
						  << counter << " " 
						  << totalRevenue << " "
						  << pricePerUnitOut << std::endl;
				//Re-start the counter and revenue
				counter = item.nr_units;
				totalRevenue = item.nr_units * pricePerUnitIn ;
				itemStart.isbn = item.isbn ;
			}
		}  //end While
		//print the last count
		pricePerUnitOut = totalRevenue / counter ;
		std::cout << itemStart.isbn << " " 
				  << counter << " " 
				  << totalRevenue << " "
				  << pricePerUnitOut << std::endl;
	} else {
		std::cerr << "There is no data to read!" << std::endl;
		return -1;

	}

	return 0;
}
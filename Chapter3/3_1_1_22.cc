#include <iostream>
#include "Sales_data.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
	Sales_data item;
	double pricePerBook = 0., totalRevenue = 0.;
	unsigned totalNrUnits = 0;

	while(cin >> item.isbn >> item.nrUnits >> pricePerBook) {
		totalNrUnits += item.nrUnits ;
		totalRevenue += item.nrUnits * pricePerBook ;
	}

	if(totalNrUnits != 0) {
		cout << item.isbn << " " 
		     << totalNrUnits << " "
		     << totalRevenue << " "
		     << totalRevenue / totalNrUnits ;

	} else {
		cout << "No books were sold!" << endl;
	}

	return 0;
}
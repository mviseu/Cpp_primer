#include <iostream>
#include "Sales_data.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
	Sales_data item1, item2, item3;
	double pricePerBook1 = 0., pricePerBook2 = 0., totalRevenue = 0.;
	unsigned totalNrUnits = 0;

	cin >> item1.isbn >> item1.nrUnits >> pricePerBook1 ;
	cin >> item2.isbn >> item2.nrUnits >> pricePerBook2 ;
	totalNrUnits = item1.nrUnits + item2.nrUnits ;
	totalRevenue = item1.nrUnits * pricePerBook1 + item2.nrUnits * pricePerBook2 ;

	if(totalNrUnits != 0) {
		cout << item1.isbn << " " 
		     << totalNrUnits << " "
		     << totalRevenue << " "
		     << totalRevenue / totalNrUnits ;

	} else {
		cout << "No books were sold!" << endl;
	}

	return 0;
}
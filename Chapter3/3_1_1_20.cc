#include <iostream>
#include "Sales_data.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
	double pricePerBook = 0.;
	Sales_data transaction;
	while(cin >> transaction.isbn >> transaction.nrUnits >> pricePerBook) {
		cout << transaction.isbn << " "
			 << transaction.nrUnits << " " 
			 << pricePerBook << " " <<endl;
	}
	return 0;

}

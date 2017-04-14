#include <iostream>
#include "Sales_data.h"

using std::cin;
using std::cout;
using std::endl;

int main() {

	Sales_data itemOld, itemNew;
	unsigned counter = 0;
	double pricePerBook = 0.;

	if (cin >> itemOld.isbn >> itemOld.nrUnits >> pricePerBook) {
		counter = 1;

		// Assumes the records for each isbn are grouped together
		while(cin >> itemNew.isbn >> itemNew.nrUnits >> pricePerBook) {
			if (itemOld.isbn == itemNew.isbn) {
				++counter;
			} else {
				cout << itemOld.isbn << " counts: " << counter << endl;
				counter = 1;
				itemOld.isbn = itemNew.isbn ;
			}

		}

		cout << itemOld.isbn << " counts: " << counter << endl;

	} else {
		cout << "No data!" << endl;
	}

	return 0;
}
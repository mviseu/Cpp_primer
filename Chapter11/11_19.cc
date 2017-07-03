#include "Sales_data_11_11.h"
#include <set>
#include <string>
#include <iostream>

using std::string;
using std::multiset;
using std::cout;
using std::endl;

bool compareISBN(const Sales_data &item1, const Sales_data &item2) {
	return item1.isbn() < item2.isbn() ;
}


int main() {
	multiset<Sales_data, decltype(compareISBN) *> multi(compareISBN);
	multiset<Sales_data, bool(*)(const Sales_data &, const Sales_data &)>::const_iterator iter = multi.cbegin();

	if(iter == multi.cend()) {
		cout << "used variable" << endl;
	}
	return 0;
}
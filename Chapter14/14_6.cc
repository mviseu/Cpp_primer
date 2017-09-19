#include "Sales_data_14_6.h"
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
	Sales_data S1("XHUY76", 3, 15);
	Sales_data S2("XHUY76", 0, 0);
	cout << S1;
	cout << S2;
	return 0;
}
#include "7_41.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

istream &read(istream &, Sales_data &);
ostream &print(ostream &, const Sales_data &);

istream &read(istream &is, Sales_data &S) {
	double price;
	is >> S.bookNo >> S.unitsSold >> price;
	S.revenue = price * S.unitsSold;
	return is;
}

ostream &print(ostream & os, const Sales_data &S) {
	auto avg_price = (S.unitsSold ? S.revenue / S.unitsSold : 0) ; 
	os << S.bookNo << " " << S.unitsSold << " "
	   << S.revenue << " " << avg_price;
	return os;
}

int main() {
	cout << "Initializing with NonDel" << endl;
	Sales_data itemNonDel("string", 1, 1);
	cout << "Initializing with default" << endl;
	Sales_data itemDefault;
	cout << "Initializing with string" << endl;
	Sales_data itemString("string");
	cout << "Initializing with cin" << endl;
	Sales_data itemCin(cin);
	return 0;
}
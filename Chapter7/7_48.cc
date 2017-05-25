#include "7_48.h"
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

#include "7_37.h"
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

//will use data from cin to initialize Sales_data
Sales_data firstItem(cin);

int main() {
	print(cout, firstItem);
	cout << endl;
	//default constructor (empty string and 0 units, revenue)
	Sales_data next;
	print(cout, next);
	cout << endl;

	//constructor with specified string and all the rest in-class initializers
	Sales_data last("9-999-99999-9");
	print(cout, last);
	cout << endl;


	return 0;
}
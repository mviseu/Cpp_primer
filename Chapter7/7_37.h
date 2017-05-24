#pragma once

#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;


class Sales_data {

friend istream &read(istream &, Sales_data &);
friend ostream &print(ostream &, const Sales_data &);

public:
	Sales_data(const string &s = "") : bookNo(s) {}
	Sales_data(const string &s, unsigned u, double p) :
	bookNo(s), unitsSold(u), revenue(p * u) {}

	Sales_data(istream & is);

private:
	string bookNo;
	unsigned unitsSold = 0;
	double revenue = 0;
};


istream &read(istream &, Sales_data &);
ostream &print(ostream &, const Sales_data &);

Sales_data::Sales_data(istream &is) {
	read(is, *this);
}
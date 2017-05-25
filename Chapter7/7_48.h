#pragma once
#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;
using std::cout;
using std::endl;


class Sales_data {

friend istream &read(istream &, Sales_data &);
friend ostream &print(ostream &, const Sales_data &);

public:

	Sales_data(const string &s, unsigned u, double p) :
	bookNo(s), unitsSold(u), revenue(p * u) {
		cout << "Body of non-delegating constructor" << endl;
	}

	//delegating constructors
	//default
	Sales_data() : Sales_data("", 0, 0) {
		cout << "Body of default delegating constructor" << endl;
	}
	//others
	Sales_data(const string &s) : Sales_data(s, 0, 0) {
		cout << "Body of string argument delegating constructor" << endl;
	};
	Sales_data(istream & is);

private:
	string bookNo;
	unsigned unitsSold = 0;
	double revenue = 0;
};


istream &read(istream &, Sales_data &);
ostream &print(ostream &, const Sales_data &);

inline Sales_data::Sales_data(istream &is) : Sales_data() {
	read(is, *this);
	cout << "Body of cin argument delegating constructor" << endl;
}
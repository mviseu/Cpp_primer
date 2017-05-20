#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

using std::string;
using std::istream;
using std::ostream;

struct Sales_data {

  // synthezised default constructor
  Sales_data() = default;
  //other options
  Sales_data(const string &s) : bookNo(s) {}
  Sales_data(const string &s, const unsigned u, const double d)
      : bookNo(s), nr_units(u), revenue(d) {}
  Sales_data(istream &);

  // member functions
  string isbn() const { return bookNo; }
  Sales_data &combine(const Sales_data &rhs) {
    nr_units += rhs.nr_units;
    revenue += rhs.revenue;
    return *this;
  }

  // data members
  string bookNo;
  unsigned nr_units = 0;
  double revenue = 0.0;
};

// interface non member functions defined/declared outside 
istream &read(istream &in, Sales_data &);
ostream &print(ostream &out, const Sales_data &S);
Sales_data add(const Sales_data &, const Sales_data &);

//constructor
Sales_data::Sales_data(istream &is) {
	read(is, *this);
}

#endif

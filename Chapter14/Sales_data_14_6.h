#ifndef SALES_DATA_7_12_H
#define SALES_DATA_7_12_H

#include <iostream>
#include <string>

using std::string;
using std::istream;
using std::ostream;

struct Sales_data;
istream &read(istream &, Sales_data &);

struct Sales_data {

  // synthezised default constructor
  Sales_data() = default;
  //other options
  Sales_data(const string &s) : bookNo(s) {}
  Sales_data(const string &s, const unsigned u, const double d)
      : bookNo(s), nr_units(u), revenue(d) {}
  Sales_data(istream & is) {
    read(is, *this);
  }

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
ostream &print(ostream &out, const Sales_data &S);
Sales_data add(const Sales_data &, const Sales_data &);

ostream &operator<<(ostream &out, const Sales_data &S) {
  out << S.isbn() << " " << S.nr_units << " " << S.revenue
      << " " << (S.nr_units ? S.revenue / S.nr_units : S.revenue);
  return out;
}

istream &operator>>(istream &in, Sales_data &S) {
  double price;
  in >> S.bookNo >> S.nr_units >> price;
  if(in) {
    S.revenue = S.nr_units * price;
  } else {
    S = Sales_data();
  }
  return in;
}

#endif

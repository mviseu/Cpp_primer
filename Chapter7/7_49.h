#pragma once
#include <iostream>
#include <string>

using std::string;
using std::istream;
using std::ostream;

class Sales_data;
istream &read(istream &, Sales_data &);

class Sales_data {

friend istream &read(istream &, Sales_data &);
friend ostream &print(ostream &out, const Sales_data &S);
friend Sales_data add(const Sales_data &, const Sales_data &);

public:
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

private:
  inline double avg_price() const;
  // data members
  string bookNo;
  unsigned nr_units = 0;
  double revenue = 0.0;
};

//inline member functions defined outside class body
double Sales_data::avg_price() const {
  return nr_units ? revenue / nr_units : 0 ;  
}

// interface non member functions defined/declared outside 
ostream &print(ostream &out, const Sales_data &S);
Sales_data add(const Sales_data &, const Sales_data &);


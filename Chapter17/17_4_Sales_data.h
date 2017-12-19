#pragma once

#include <iostream>
#include <string>

using std::string;
using std::istream;
using std::ostream;

struct Sales_data;
istream &read(istream &, Sales_data &);

namespace std {
template <typename T> class hash;
}

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

  //there is a single mapping logic between a string and a sales_data that identifies book
  explicit operator string() const {return bookNo;}
  //not a great idea to map a double since there is no evident transformation that the user can expect
  //explicit operator double() const {return revenue;}

  Sales_data &operator=(const string &s) {
    *this = Sales_data(s);
    return *this;
  }

  Sales_data &operator+=(const Sales_data &rhs) {
    nr_units += rhs.nr_units;
    revenue += rhs.revenue;
    return *this;
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

ostream &operator<<(ostream &out, const Sales_data &S);
istream &operator>>(istream &in, Sales_data &S);
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
bool operator==(const Sales_data &lhs, const Sales_data &rhs);
bool operator!=(const Sales_data &lhs, const Sales_data &rhs);

// compare isbn
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs);

// specializing the hash function for Sales_data
namespace std {

template <> struct hash<Sales_data> {
  using result_type = size_t;
  using argument_type = Sales_data;
  size_t operator()(const Sales_data &s) const {
    return hash<string>()(s.bookNo) ^
           hash<unsigned>()(s.nr_units) ^
           hash<double>()(s.revenue);  
  }
};

} // end namespace std

#pragma once
#include <string>

struct Sales_data {

  // synthezised default constructor
  Sales_data() = default;
  //other options
  Sales_data(const std::string &s) : bookNo(s) {}
  Sales_data(const std::string &s, const unsigned u, const double d)
      : bookNo(s), nr_units(u), revenue(d) {}
  Sales_data(const Sales_data &) = default;
  Sales_data(Sales_data &&) = default;
  Sales_data &operator=(const Sales_data &) = default;
  Sales_data &operator=(Sales_data &&) = default;
  ~Sales_data() = default;

  // member functions
  std::string isbn() const { return bookNo; }
  Sales_data &combine(const Sales_data &rhs) {
    nr_units += rhs.nr_units;
    revenue += rhs.revenue;
    return *this;
  }
  double avg_price() const {
    return (nr_units ? revenue / nr_units : 0); 
  }

  // data members
  std::string bookNo;
  unsigned nr_units = 0;
  double revenue = 0.0;
};
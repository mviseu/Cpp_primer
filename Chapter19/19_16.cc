#include <string>
#include <iostream>

struct Sales_data {

  // synthezised default constructor
  Sales_data() = default;
  //other options
  Sales_data(const std::string &s) : bookNo(s) {}
  Sales_data(const std::string &s, const unsigned u, const double d)
      : bookNo(s), nr_units(u), revenue(d) {}

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

int main() {
  Sales_data sd("Book", 3, 20);
  double (Sales_data::*ptr_avg_price)() const = &Sales_data::avg_price;
  std::cout << (sd.*ptr_avg_price)() << std::endl;
  return 0;
}
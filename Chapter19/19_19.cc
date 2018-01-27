#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>

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
  Sales_data sd1("Book", 3, 20); // 6.67
  Sales_data sd2("Book2", 10, 100); // 10
  Sales_data sd3("Book3", 20, 5); // 4

  std::vector<Sales_data> vec = {sd3, sd2, sd1};
  auto greater_5 = std::find_if(vec.cbegin(), vec.cend(), [](const Sales_data &sd) -> bool {
    auto call_avg_price = std::mem_fn(&Sales_data::avg_price);
    return (call_avg_price(sd) > 7);
  });
  if(greater_5 != vec.cend()) {
    std::cout << greater_5 -> isbn() << std::endl;
  }
  return 0;
}
#include "Sales_data.h"

using std::string;
using std::istream;
using std::ostream;

istream &read(istream &in, Sales_data &S) {
  in >> S.bookNo >> S.nr_units >> S.revenue;
  return in;
}
ostream &print(ostream &out, const Sales_data &S) {
  out << S.bookNo << " " << S.nr_units << " " << S.revenue << " "
      << (S.revenue == 0 ? S.revenue : S.revenue / S.nr_units) << std::endl;
  return out;
}

ostream &operator<<(ostream &out, const Sales_data &S) {
  out << S.isbn() << " " << S.nr_units << " " << S.revenue
      << " " << (S.nr_units ? S.revenue / S.nr_units : S.revenue) << std::endl;
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

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;
  return sum += rhs; 
}

bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
  return lhs.bookNo == rhs.bookNo && 
  		 lhs.nr_units == rhs.nr_units &&
  		 lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs) {
  return !(lhs == rhs);
}
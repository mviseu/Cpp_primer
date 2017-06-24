#include "Sales_data_10_12.h"
#include <iostream>

using std::endl;

istream &read(istream &, Sales_data &);
ostream &print(ostream &out, const Sales_data &S);

istream &read(istream &in, Sales_data &S) {
  in >> S.bookNo >> S.nr_units >> S.revenue;
  return in;
}

ostream &print(ostream &out, const Sales_data &S) {
  out << S.bookNo << " " << S.nr_units << " " << S.revenue << " "
      << (S.revenue == 0 ? S.revenue : S.revenue / S.nr_units) << endl;
  return out;
}
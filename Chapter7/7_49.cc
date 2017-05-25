#include "7_49.h"
#include <iostream>

using std::cin;
using std::cout;
using std::istream;
using std::ostream;
using std::cerr;
using std::endl;

// function declarations
istream &read(istream &in, Sales_data &);
ostream &print(ostream &out, const Sales_data &S);
inline bool compareIsbn(const Sales_data &S1, Sales_data &S2);

istream &read(istream &in, Sales_data &S) {
  in >> S.bookNo >> S.nr_units >> S.revenue;
  return in;
}

ostream &print(ostream &out, const Sales_data &S) {
  out << S.bookNo << " " << S.nr_units << " " << S.revenue << " "
      << S.avg_price() << endl;
  return out;
}

inline bool compareIsbn(const Sales_data &S1, Sales_data &S2) {
  return S1.isbn() == S2.isbn();
}
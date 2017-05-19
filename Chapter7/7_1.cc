#include "Sales_data.h"
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
Sales_data &combine(Sales_data &lhs, const Sales_data &rhs);

istream &read(istream &in, Sales_data &S) {
  in >> S.bookNo >> S.nr_units >> S.revenue;
  return in;
}

ostream &print(ostream &out, const Sales_data &S) {
  out << S.bookNo << " " << S.nr_units << " " << S.revenue << " "
      << S.revenue / S.nr_units << endl;
  return out;
}

inline bool compareIsbn(const Sales_data &S1, Sales_data &S2) {
  return S1.bookNo == S2.bookNo;
}

Sales_data &combine(Sales_data &lhs, const Sales_data &rhs) {
  lhs.nr_units += rhs.nr_units;
  lhs.revenue += rhs.revenue;
  return lhs;
}

int main() {
  Sales_data total;
  if (read(cin, total)) {
    Sales_data trans;
    while (read(cin, trans)) {
      if (compareIsbn(total, trans)) {
        combine(total, trans);
      } else {
        print(cout, total);
        total = trans;
      }
    }

  } else {
    cerr << "No data?" << endl;
  }
  print(cout, total);
  return 0;
}
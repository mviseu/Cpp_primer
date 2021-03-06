#include "Sales_data.h"
#include <iostream>

using std::cin;
using std::cout;
using std::istream;
using std::ostream;
using std::cerr;
using std::endl;

// function declarations (for consistency check)
istream &read(istream &in, Sales_data &);
ostream &print(ostream &out, const Sales_data &S);
inline bool compareIsbn(const Sales_data &S1, Sales_data &S2);

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
  return S1.isbn() == S2.isbn();
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;
  sum.combine(rhs);
  return sum;
}

int main() {
  Sales_data total;
  if (read(cin, total)) {
    Sales_data trans;
    while (read(cin, trans)) {
      if (compareIsbn(total, trans)) {
        total.combine(trans);
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
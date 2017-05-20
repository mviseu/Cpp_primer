#include "Sales_data_7_12.h"
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
      << S.revenue / S.nr_units << endl;
  return out;
}

inline bool compareIsbn(const Sales_data &S1, Sales_data &S2) {
  return S1.isbn() == S2.isbn();
}

int main() {
  Sales_data total(cin);
  if (cin) {
    Sales_data trans(cin);
    while (cin) {
      if (compareIsbn(total, trans)) {
        total.combine(trans);
      } else {
        print(cout, total);
        total = trans;
      }
      trans = Sales_data(cin);
    }
  print(cout, total);

  } else {
    cerr << "No data?" << endl;
  }
  return 0;
}
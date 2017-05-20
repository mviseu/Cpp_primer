#include <iostream>
#include "Sales_data_7_14.h"

using std::cin;
using std::cout;
using std::ostream;
using std::endl;

istream &read(istream &, Sales_data &); 
ostream &print(ostream &out, const Sales_data &);

istream &read(istream &in, Sales_data &S) {
  in >> S.bookNo >> S.nr_units >> S.revenue;
  return in;
}
ostream &print(ostream &out, const Sales_data &S) {
  out << S.bookNo << " " << S.nr_units << " " << S.revenue << " "
      << (S.revenue == 0 ? S.revenue : S.revenue / S.nr_units) << endl;
  return out;
}

int main() {
	//Test all constructors
	Sales_data item, item2{"TEST"}, 
			   item3("IH4XK", 5, 6), item4(cin);
	//print 
	cout << "default: ";
	print(cout, item);
	cout << "isbn only: ";
	print(cout, item2);
	cout << "isbn, units, revenue: ";
	print(cout, item3);
	cout << "cin: ";
	print(cout, item4);
	return 0;
}
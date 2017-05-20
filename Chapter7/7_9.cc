#include "Person.h"
#include <iostream>

using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;
//declaring functions for consistency check
istream & read(istream &, Person &);
ostream & print(ostream &, Person &);

istream & read(istream &is, Person &Y) {
	is >> Y.NameID >> Y.AddressID;
	return is;
}

ostream & print(ostream &os, Person &Y) {
	os << Y.NameID << " " << Y.AddressID;
	return os;	
}

int main() {
  Person P;

  //using non-member interface functions
  read(cin, P);
  print(cout, P);

  return 0;
}

#include <iostream>
#include "7_50.h"

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

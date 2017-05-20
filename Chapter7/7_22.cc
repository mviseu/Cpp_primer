#include <iostream>
#include "7_22.h"

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
	read(cin, P);
	Person Y(P);
	cout << Y.Name() << " " << Y.Address() << endl;
	cout << Y.Name() << " " << P.Name() << endl;
	Person X(1, "Name");
	Person Z(2, "Address");

	cout << "X: " << X.Name() <<  " " << X.Address() << endl;
	cout << "Z: " << Z.Name() <<  " " << Z.Address() << endl;
	return 0;
}
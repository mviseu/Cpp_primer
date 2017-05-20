#include <iostream>
#include "7_15.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
	Person P;
	cin >> P.NameID >> P.AddressID;
	Person Y(P);
	cout << Y.Name() << " " << Y.Address() << endl;
	Y.NameID = "Baltazar";
	cout << Y.Name() << " " << P.Name() << endl;
	Person X(1, "Name");
	Person Z(2, "Address");

	cout << "X: " << X.Name() <<  " " << X.Address() << endl;
	cout << "Z: " << Z.Name() <<  " " << Z.Address() << endl;
	return 0;
}
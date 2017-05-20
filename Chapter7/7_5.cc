#include "Person.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
  // using data members to read from input
  Person P;

  if (cin >> P.NameID >> P.AddressID) {
    // using member function to write to output
    cout << P.Name() << endl;
    cout << P.Address() << endl;
  }
  return 0;
}

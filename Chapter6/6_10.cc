#include <iostream>
#include "Chapter6.h"

using std::cin;
using std::cout;
using std::endl;

void swap2ints(int &i1, int &i2) {
  // save the value of i1 in a copy
  const auto aux = i1;
  i1 = i2;
  i2 = aux;
}

int main() {
  cout << "Please provide 2 ints" << endl;

  int integer1, integer2;

  cin >> integer1 >> integer2;

  swap2ints(integer1, integer2);

  cout << "The value of the first int is now: " << integer1 << endl;
  cout << "The value of the second int is now: " << integer2 << endl;

  return 0;
}
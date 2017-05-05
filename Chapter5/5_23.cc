#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

  cout << "Please provide 2 ints for division" << endl;

  int i1, i2;

  cin >> i1 >> i2;

  cout << i1 << " divided by " << i2 << " is: " << i1 / i2 << endl;

  return 0;
}
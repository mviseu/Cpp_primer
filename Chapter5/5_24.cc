#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main() {

  cout << "Please provide 2 ints for division" << endl;

  int i1, i2;

  cin >> i1 >> i2;

  if(i2 == 0) {
  	throw runtime_error("The second integer is zero!"); 
  }

  cout << i1 << " divided by " << i2 << " is: " << i1 / i2 << endl;

  return 0;
}
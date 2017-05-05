#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main() {

  cout << "Please provide 2 ints for division" << endl;

  int i1, i2, result;
  cin >> i1;

  while (cin >> i2) {
    try {
      if(i2 == 0) {
        throw runtime_error("The second integer is zero!"); 
      }

      result = i1 / i2;
      break;

    } catch (runtime_error err) {
      cout <<  err.what() << " Please supply a new second integer" << endl;
    } 
  }


  cout << i1 << " divided by " << i2 << " is: " << result << endl;
  return 0;
}
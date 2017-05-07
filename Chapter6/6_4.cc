#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int fact(int val) {

  int result = 1;

  while (val > 1) {
    result *= val--;
  }
  return result;
}

int main() {
  cout << "Please provide a positive int to calculate its factorial" << endl;
  int number;
  cin >> number;

  cout << "Factorial of " << number << " is: " << fact(number) << endl;
  return 0;
}
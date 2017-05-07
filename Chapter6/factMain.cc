#include <iostream>
#include "Chapter6.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
  cout << "Please provide a positive int to calculate its factorial" << endl;
  int number;
  cin >> number;

  cout << "Factorial of " << number << " is: " << fact(number) << endl;
  return 0;
}
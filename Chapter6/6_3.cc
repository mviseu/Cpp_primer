#include <iostream>

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
	cout << "Factorial of 5 is: " << fact(5) << endl;
	return 0;
}
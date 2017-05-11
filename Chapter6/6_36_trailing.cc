#include <iostream>
#include <string>

using std::endl;
using std::cout;
using std::string;

auto initializeArrayWithCommonString(string (&inputArray)[10], const string &s) -> string (&)[10] {
  size_t i = 0;
  for (auto &s2 : inputArray) {
    inputArray[i++] = s;
  }
  return inputArray;
}

int main() {
  string arrayOfStrings[10] {};

  initializeArrayWithCommonString(arrayOfStrings, "hello");

  //print new array
  for (const auto &c : arrayOfStrings) {
  	cout << c << endl;
  }

  return 0;
}

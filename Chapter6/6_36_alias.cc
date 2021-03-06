#include <iostream>
#include <string>

using std::endl;
using std::cout;
using std::string;

using arrayStr = string[10];

arrayStr &initializeArrayWithCommonString(string (&inputArray)[10], const string &s) {
  size_t i = 0;
  for (auto &s2 : inputArray) {
    inputArray[i++] = s;
  }
  return inputArray;
}

int main() {
  string arrayOfStrings[10] {};

  initializeArrayWithCommonString(arrayOfStrings, "hi");

  //print new array
  for (const auto &c : arrayOfStrings) {
  	cout << c << endl;
  }

  return 0;
}

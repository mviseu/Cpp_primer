#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {

  string newString, oldString;
  bool duplicatedWord = false;

  while (cin >> newString) {
    if (!isupper(newString[0]))
      continue;

    if (oldString == newString) {
      duplicatedWord = true;
      break;
    } else {
      oldString = newString;
    }
  }
  // break transfers control here

  duplicatedWord == false ? cout << "There are no duplicated words" << endl
                          : cout << "Duplicate word is: " << newString << endl;
  return 0;
}
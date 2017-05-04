#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {

  string rsp;

  do {
    cout << "Please provide 2 strings" << endl;
    string s1, s2;
    cin >> s1 >> s2;

    if (s1 == s2) {
      cout << "Both strings are equal!" << endl;
    } else {

      if (s1 < s2) {
        cout << "String 1 is less than string 2" << endl;
      } else {
        cout << "String 2 is less than string 1" << endl;
      }
    }
    cout << "Compare more strings (y/n)?" << endl;
    cin >> rsp;
  }

  while (rsp == "y");

  return 0;
}
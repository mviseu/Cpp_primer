#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  string s;
  //read the input into s
  cin >> s;
  //change all characters in string to X
  for (auto &c : s) {
    c = 'X';
  }
  cout << s << endl;
  return 0;
}

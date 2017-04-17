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
  //this forrange will change c which is a copy of the characters of s
  //it will not change s
  for (char c : s) {
    c = 'X';
    cout << c << endl;
  }
  cout << s << endl;
  return 0;
}

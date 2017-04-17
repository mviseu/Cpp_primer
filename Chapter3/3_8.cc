#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {

  string s;
  decltype(s.size()) index = 0;

  cin >> s;
/*  while(index < s.size()) {
    s[index] = 'X';
    ++index;
  } */
  for(decltype(s.size()) index = 0; index < s.size(); ++index)
    s[index] = 'X';
  
  cout << s << endl;
  return 0;
}

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

//isShorter cannot be constexpr since string arguments are non literal type
inline bool isShorter(const string &s1, const string &s2) {
  return s1.size() < s2.size();
}

int main() {
  cout << isShorter("hello", "goodbye") << endl;
  return 0;
}
#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;

bool str_subrange(const string &str1, const string &str2) {
  if (str1.size() == str2.size()) {
    return str1 == str2;
  }

  auto size = str1.size() < str2.size() ? str1.size() : str2.size();

  for (decltype(size) index = 0; index < size; ++index) {
    if (str1[index] != str2[index]) {
      return false;
    }
  }
  return true;
}


int main() {
  const string s1("Compare"), s2("strings");
  str_subrange(s1, s1);
  return 0;
}
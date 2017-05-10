#include <initializer_list>
#include <iostream>

using std::initializer_list;
using std::cout;
using std::endl;

int sum(initializer_list<int> list) {
  int result = 0;
  for (const auto &i : list) {
    result += i;
  }
  return result;
}

int main() {
  cout << sum({1, 2, 3, 4}) << endl;
  return 0;
}
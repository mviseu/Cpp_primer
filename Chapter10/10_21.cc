#include <iostream>

using std::cout;
using std::endl;

int main() {

  auto a = 3;
  auto f = [&a]() -> bool {
    if (a == 0) {
      return true;
    } else {
      --a;
      return false;
    }
  };
  while (!f()) {
    cout << a << endl;
  };

  return 0;
}
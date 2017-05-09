#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::begin;

int largerValue(const int i, const int *p) {
    if (i > *p) {
      return i;
    } else {
      return *p;
    }
  }

int main() {

  int array[2] = {2, 2};
  int j = 3;

  cout << largerValue(j, begin(array)) << endl;

  return 0;
}
#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <vector>

using std::copy;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::shared_ptr;
using std::make_shared;

shared_ptr<vector<int>> factory() { return make_shared<vector<int>>(); }

istream &read(istream &is, vector<int> &vec) {
  for (int i = 0; is >> i; vec.push_back(i))
    ;
  return is;
}

ostream_iterator<int> &print(ostream_iterator<int> &out,
                             const vector<int> &vec) {
  copy(vec.cbegin(), vec.cend(), out);
  return out;
}

void use_factory() {
  auto p = factory();
  read(cin, *p);

  ostream_iterator<int> out(cout, " ");
  print(out, *p);
}

int main() {
  use_factory();
  return 0;
}
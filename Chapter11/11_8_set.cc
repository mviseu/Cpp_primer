#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>

int main() {
  std::ifstream input("infile");
  std::istream_iterator<std::string> in(input), eof;
  std::ostream_iterator<std::string> out(std::cout, " ");

  std::set<std::string> set(in, eof);
  copy(set.cbegin(), set.cend(), out);
  out = "\n";
  //no need to sort or unique!
  return 0;
}
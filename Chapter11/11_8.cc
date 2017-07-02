#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>

void elimDupl(std::vector<std::string> &vec) {
  std::sort(vec.begin(), vec.end());
  auto start_dupl = std::unique(vec.begin(), vec.end());
  vec.erase(start_dupl, vec.end());

}

int main() {
  std::ifstream input("infile");
  std::istream_iterator<std::string> in(input), eof;
  std::ostream_iterator<std::string> out(std::cout, " ");

  std::vector<std::string> vec(in, eof);
  copy(vec.cbegin(), vec.cend(), out);
  elimDupl(vec);
  out = "\n";
  copy(vec.cbegin(), vec.cend(), out); 
  
 /* std::set<std::string> set(in, eof);
  std::copy(set.cbegin(), set.cend(), out);*/


  return 0;
}
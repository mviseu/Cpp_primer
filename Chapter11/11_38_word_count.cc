#include <algorithm>
#include <fstream>
#include <iterator>
#include <unordered_map>
#include <set>
#include <string>
#include <iostream>

using std::cout;
using std::endl;

int main() {
  std::ifstream infile("infile");
  if (!infile.good()) {
    return -1;
  }
  std::istream_iterator<std::string> in_iter(infile), eof;
  std::unordered_map<std::string, size_t> word_count;

  std::for_each(in_iter, eof,
                [&word_count](const std::string &word) { ++word_count[word]; });

  for(const auto &w : word_count) {
  	cout << w.first << " " << w.second << endl;
  }
  return 0;
}
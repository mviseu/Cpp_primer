#include <algorithm>
#include <fstream>
#include <iterator>
#include <map>
#include <set>
#include <string>

int main() {
  std::ifstream infile("infile");
  if (!infile.good()) {
    return -1;
  }
  std::istream_iterator<std::string> in_iter(infile), eof;
  std::map<std::string, size_t> word_count;

  std::for_each(in_iter, eof,
                [&word_count](const std::string &word) { ++word_count[word]; });

  return 0;
}
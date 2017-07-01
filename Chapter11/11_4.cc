#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <vector>

std::string lowercaseNoPunct(const std::string &s) {
  std::string s_low;
  std::transform(s.cbegin(), s.cend(), back_inserter(s_low),
                 [](char c) { return tolower(c); });
  auto start_remove = std::remove_if(s_low.begin(), s_low.end(), ispunct);
  s_low.erase(start_remove, s_low.end());
  return s_low;
}

int main() {
  std::ifstream infile("infile");
  if (!infile.good()) {
    return -1;
  }
  std::istream_iterator<std::string> in_iter(infile), eof;
  std::map<std::string, size_t> word_count;

  std::vector<std::string> words;
  std::set<std::string> excluded = {"a", "the"};
  std::transform(in_iter, eof, back_inserter(words), lowercaseNoPunct);
  std::for_each(words.begin(), words.end(),
                [&word_count, &excluded](const std::string &word) {
                  if (excluded.find(word) == excluded.cend()) {
                    ++word_count[word];
                  }
                });
  for (const auto &e : word_count) {
    std::cout << e.first << " " << e.second << " " << std::endl;
  }

  return 0;
}
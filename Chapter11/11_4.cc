#include <algorithm>
#include <fstream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <cctype>
#include <vector>
#include <iostream>

std::string lowercase(const std::string &s) {
  std::string s_low; 
  std::transform(s.cbegin(), s.cend(), back_inserter(s_low), [](char c) {return tolower(c);});
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
  std::transform(in_iter, eof, back_inserter(words), lowercase);
  std::for_each(words.begin(), words.end(), [&word_count](std::string &word) {
  	++word_count[word];
  });
  for(const auto &e : word_count) {
    std::cout << e.first << " " << e.second << " " << std::endl;
  }

  return 0;
}
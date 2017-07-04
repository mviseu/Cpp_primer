#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>

using std::multimap;
using std::set;
using std::string;
using std::cout;
using std::endl;
using std::map;

int main() {
  multimap<string, string> bookstore = {{"Jane Austen", "Pride and Prejudice"},
                                        {"Shakespeare", "Romeo and Juliet"},
                                        {"Shakespeare", "Hamlet"}};

  map<string, set<string>> unique_bookstore;
  for(const auto &val : bookstore) {
    unique_bookstore[val.first].insert(val.second);
  }
  for(const auto &val : unique_bookstore) {
    cout << val.first << " ";
    for(const auto &book : val.second) {
      cout << book << " ";
    }
    cout << endl;
  }

  return 0;
}
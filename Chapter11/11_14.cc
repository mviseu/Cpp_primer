#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <utility>
#include <vector>

using std::map;
using std::string;
using std::vector;
using std::pair;
using std::back_inserter;
using std::cout;
using std::endl;

class Families {
public:
  using child = pair<string, string>;
  using children = vector<child>;
  using family = pair<string, children>;

  Families &addFamily(const family &fam) {
    families[fam.first] = fam.second;
    return *this;
  }

  Families &addChildren(const string &surname, const children &childr) {
    std::copy(childr.cbegin(), childr.cend(),
              std::back_inserter(families[surname]));
    return *this;
  }

  void print() const {
    for (const auto &fam : families) {
      cout << fam.first << " ";
      for (const auto &child : fam.second) {
        cout << child.first << " " << child.second << " ";
      }
      cout << endl;
    }
  }

private:
  map<string, children> families;
};

int main() {
  // empty map
  Families families;
  // add a family
  Families::children childr = {
      {"Ella", "2/10/2000"}, {"Beth", "3/10/1998"}, {"John", "3/10/1998"}};

  families.addFamily(std::make_pair(string("Smith"), childr));

  Families::children new_children = {{"Mary", "2/10/1990"},
                                     {"William", "2/10/1990"}};

  families.addChildren(string("Smith"), new_children);

  families.print();
  return 0;
}
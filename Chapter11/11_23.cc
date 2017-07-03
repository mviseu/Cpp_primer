#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <utility>
#include <vector>

using std::multimap;
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
    families.insert(fam);
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
  multimap<string, children> families;
};

int main() {
  // empty map
  Families families;
  // add a family
  Families::children childr = {
      {"Ella", "2/10/2000"}, {"Beth", "3/10/1998"}, {"John", "3/10/1998"}};

  families.addFamily(std::make_pair(string("Smith"), childr));

  families.print();
  return 0;
}
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {

  vector<int> v1 = {1, 2}, v2 = {1, 2, 3, 4};

  if (v1.empty() || v2.empty()) {
    cout << "One or both of the vectors are empty" << endl;
    return 0;
  }

  bool prefix = true;

  for (decltype(v1.size()) index = 0; index < v1.size() && index < v2.size();
       ++index) {
    if (v1[index] != v2[index])
      prefix = false;
  }

  cout << "Is the smaller vector a prefix of the larger vector?" << endl;
  if (prefix == true) {
    cout << "true" << endl;

  } else {
    cout << "false" << endl;
  }

  return 0;
}
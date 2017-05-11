#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

void printVectorStringElements(vector<string>::const_iterator beg,
                               vector<string>::const_iterator end) {
  if (beg != end) {
    cout << *beg << " ";
    printVectorStringElements(beg + 1, end);
  } else {
  	cout << endl;
  }
}


void printVectorStringElements(const vector<string> &vs) {
  printVectorStringElements(vs.cbegin(), vs.cend());
}


int main() {

  const vector<string> vec = {"These", "strings", "will", "be", "printed"};
  printVectorStringElements(vec);

  return 0;
}
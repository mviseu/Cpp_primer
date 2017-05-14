#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <cassert>

using std::cout;
using std::endl;
using std::cerr;
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
#ifndef NDEBUG
  decltype(vs.size()) threshold = 10;
  if (vs.size() > threshold) {
    cerr << "Error in function " << __func__ << " in file " << __FILE__
         << " at time " << __TIME__ << " and date " << __DATE__ 
         << ". The vector is too long!" << endl;
  }
#endif
  assert(vs.size() < threshold);
  printVectorStringElements(vs.cbegin(), vs.cend());
}

int main() {

  const vector<string> vec = {"These", "strings", "will", "be", "printed",
                              "These", "strings", "will", "be", "printed",
                              "These", "strings", "will", "be", "printed",
                              "These", "strings", "will", "be", "printed"};
  printVectorStringElements(vec);

  return 0;
}
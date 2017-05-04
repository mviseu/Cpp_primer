#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {

  // idiomatic use of a while loop

  int i;
  while (cin >> i) {
    cout << "Printing input int values..." << i << endl;
  }

  /*
  //equivalent for loop: expression is empty and int is initialized in
  init-statement
  for(int i; cin >> i; ) {
          cout << "Printing input int values..." << i << endl;
  } */

  vector<string> vecS = {"I", "am", "a", "vector", "of", "strings"};

  // idiomatic use of the for loop (step)
  for (decltype(vecS.size()) index = 0; index != vecS.size(); ++index) {
    cout << vecS[index] << " ";
  }

  /*
  //alternative while loop
  //int declaration is outside the while loop and increment inside the body
  decltype(vecS.size()) index = 0;
  while(index != vecS.size()) {
          cout << vecS[index] << " ";
          ++index;
  } */

  return 0;
}
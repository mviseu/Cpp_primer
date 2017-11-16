#include "16_14_Screen.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
  // Create a screen of x's with width and height 5
  Screen<5,5>myScreen('X');
  // move the cursor to (4,0). Get a copy 1.
  // set character # on the copy 1 at position 4,0. copy the result to copy2.
  // display the contents of copy2 screen. return another copy3.
  myScreen.move(4, 0).set('#').display(cout);
  cout << "\n";
  // display the contents of myScreen which should be all XXX's
  //myScreen.display(cout);
  cout << myScreen;
  cout << "\n";
  Screen<5,5> inScreen;
  cin >> inScreen;
  std::cout << "\n-----\n" << inScreen << "\n-----\n";
  return 0;
}
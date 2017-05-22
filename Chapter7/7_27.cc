#include "7_27_Screen.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  // Create a screen of x's with width and height 5
  Screen myScreen(5, 5, 'X');
  // move the cursor to (4,0). set # at position 4,0. display the contents of
  // screen.
  myScreen.move(4, 0).set('#').display(cout);
  cout << "\n";
  // display the same contents
  myScreen.display(cout);
  cout << "\n";
  return 0;
}
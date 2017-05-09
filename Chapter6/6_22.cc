#include <iostream>

using std::cout;
using std::endl;

void swapPointers(const int * &rp1, const int * &rp2) {
  const int *aux = rp1;
  rp1 = rp2;
  rp2 = aux;
}

int main() {
  const int i1 = 0, i2 = 1;
  const int *p1Main = &i1, *p2Main = &i2;
  swapPointers(p1Main, p2Main);
  cout << "First pointer points to: " << *p1Main << endl;
  cout << "Second pointer points to: " << *p2Main << endl;
  return 0;
}


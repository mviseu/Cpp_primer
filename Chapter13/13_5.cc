#include "HasPtr.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	HasPtr p("Hello");
	HasPtr q(p);
	q = p;
	return 0;
}
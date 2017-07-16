#include "numbered.h"
#include <iostream>

using std::cout;
using std::endl;

void f(numbered s) {
	cout << s.mysn << endl;
}
int main() {
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);
	return 0;
}
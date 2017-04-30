#include <iostream>

using std::cout;
using std::endl;

//what happens when we shift more than the size of the type?

int main() {
	//maximum shift is 32 - 1 = 31
	cout << (1U << 31) << endl ;s

	return 0;
}
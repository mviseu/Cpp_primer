#include <iostream>

using std::cout;
using std::endl;

int main() {
	int x[10];
	int *p = x; //pointer to the first element of the array

	//size of the array = 4 * 10 / 4 = 10
	cout << sizeof(x) / sizeof(*x) << endl;
	//size of a pointer divided by the size of the type to which it points to
	// = 8 / 4 = 2
	cout << sizeof(p) / sizeof(*p) << endl;
 
	return 0;
}
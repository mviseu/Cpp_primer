//show 3 expressions that will overflow
#include <iostream>

using std::cout;
using std::endl;


int main() {
	//Overflow examples

	constexpr short a = 32800; 

	constexpr unsigned short b = 65536;

	constexpr unsigned char c = -1;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	return 0;
}
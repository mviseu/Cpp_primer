#include <iostream>

using std::cout;
using std::endl;


int main() {
	unsigned long ul1 = 3, ul2 = 7;

	//ul1 and ul2 are both non zero values -> result is true. cout prints 1.
	cout << "logical &&: " << (ul1 && ul2) << endl;

	// 3 is 00000000 00000000 00000000 ... 00000011
	// 7 is ...                            00000111 
	// &&								.. 00000011 returns 3

	cout << "bitwise &: " << (ul1 & ul2) << endl;


	// logical or evaluates only right hand operand, returns true -> cout is 1
	cout << "logical ||: " << (ul1 || ul2 ) << endl;


	//bitwise | .. 00000011
	//          .. 00000111
	//             00000111 returns 7!


	cout << "bitwise |: " << (ul1 | ul2) << endl;
	return 0;
}
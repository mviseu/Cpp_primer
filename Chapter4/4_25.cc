#include <iostream>

using std::cout;
using std::endl;


int main() {

	//'q' is 01110001 = 64 + 32 + 16 + 1 = 113
	//~'q' promotes to char to int and inverts
	// 11111111 11111111 11111111 100011 10 = 4294967295 - 1 - 16 - 32 - 64 = 4294967182
	// ~U'q' << 6 = 11111111 11111111 11100011 10000000 = 4294967295 - 1024 - 2048 - 4096 - 127 = 
	//4294960000

	cout << U'q' << endl;
	cout << ~U'q' << endl;
	cout << (~U'q' << 6 ) << endl;

	return 0;
}
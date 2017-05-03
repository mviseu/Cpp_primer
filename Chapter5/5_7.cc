#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

	int i;
	cin >> i;
	if(int ival = i) {
		cout << "ival = " << ival << endl;
	}
	//has to be else if for ival to be a declared variable
	else if(!ival) {
		cout << "ival = 0\n";
		}

	return 0;
}
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	int int1 = 0, int2 = 0;
	cout << "Please provide 2 integers:" << endl;
	cin >> int1 >> int2;
	if(int1 < int2) {
		for(int1; int1 <= int2; ++int1) {
			cout << int1 << endl; 
		}
	} else {
		for(int2; int2 <= int1; ++int2) {
			cout << int2 << endl;
		}
	}
	return 0;
}
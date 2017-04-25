#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	cout << "This program will read input integers and stop when the input is 42..." << endl;

	int i = 0;


	while(cin >> i && i != 42) {
		cout << "This is not 42" << endl;
	}

	cout << "Found 42!!" << endl;

	return 0;
}

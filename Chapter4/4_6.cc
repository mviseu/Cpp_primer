#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

	int number = 0;

	cout << "Please provide an int" << endl;

	cin >> number;

	if(number % 2 == 0) {
		cout << "The number is even!" << endl;
	} else {
		cout << "The number is odd!" << endl;
	}

	return 0;
}
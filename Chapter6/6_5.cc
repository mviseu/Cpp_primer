#include <iostream>

using std::cin;
using std::cout;
using std::endl;


inline double absolute(double val) {

	double absoluteVal;

	if (val < 0) {
		absoluteVal = -val;
	} else {
		absoluteVal = val;
	}

	return absoluteVal;
}

int main() {
	cout << "Please provide a number" << endl;
	double number;
	cin >> number;

	cout << "The absolute value of " << number << " is: " << absolute(number) << endl; 

	return 0;
}
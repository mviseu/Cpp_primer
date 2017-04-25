#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	int a, b, c, d;
	cout << "a:" << endl;
	cin >> a;
	cout << "b:" << endl;
	cin >> b;
	cout << "c:" << endl;
	cin >> c;
	cout << "d:" << endl;
	cin >> d;

	if (a > b && b > c && c > d) {
		cout << "a > b > c > d is True" << endl;
	} else {
		cout << "a > b > c > d is False" << endl;	
	}

	return 0;
}


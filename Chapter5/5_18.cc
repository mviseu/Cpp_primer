#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

	do {
		int v1, v2;
		cout << "Enter 2 numbers to sum:";
		if (cin >> v1 >> v2)
			cout << "Sum is: " << v1 + v2 << endl;

	} while(cin);

	return 0;
}
/*
Instructions: read a sequence of ints from cin and store those values in a vector
*/
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {

	vector<int> v1;
	int i;

	while(cin >> i) {
		v1.push_back(i);
	}

	for(auto &c : v1) {
		cout << c << endl;
	}

	return 0;
}
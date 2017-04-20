#include <iostream>

using std::cout;
using std::endl;

int main() {

	unsigned scores[11] = {};
	unsigned scoresNoListInit[11];

	for(const auto &c : scores) {
		cout << c << " ";
	}

	cout << endl;

	for(const auto &c : scoresNoListInit) {
		cout << c << " ";
	}

	cout << endl;
	return 0;
}
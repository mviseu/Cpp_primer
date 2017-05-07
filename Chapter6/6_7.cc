#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<int> sequenceNrCalls() {
	static vector<int> v;
	static size_t counterCalls = 0;
	v.push_back(counterCalls++);
	for(const auto &c : v) {
		cout << c << " " ;
	}
	cout << endl;
	return v;
}

int main() {
	cout << "Please provide the number of times that a function is called" << endl;
	size_t nrCalls;
	cin >> nrCalls;
	for(size_t counter = 0; counter < nrCalls; ++counter) {
		sequenceNrCalls();
	}
	return 0;
}


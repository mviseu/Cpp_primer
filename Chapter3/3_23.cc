#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
	vector<int> v(10);

	//Reading 10 int values
	cout << "Provide 10 int values" << endl;

	for(auto &c : v) {
		int element = 0;
		if (cin >> element) {
			c = element ;
		} else {
			cout << "Must provide 10 integer values!" << endl;
			return -1;
		}
	}

	//using iterators assign each element a value that is twice its value
	for(auto it = v.begin(); it != v.end(); ++it) {
		*it *= 2;
		cout << *it << endl;
	}

	return 0;
}
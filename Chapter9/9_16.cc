#include <vector>
#include <iostream>
#include <list>

using std::vector;
using std::cout;
using std::endl;
using std::list;

int main() {
	vector<int> v1 = {0, 1, 2, 3};
	list<int>	l1 = {0, 1, 2, 3};


	cout << (vector<int>(l1.cbegin(), l1.cend()) == v1 ? "True" : "False") << endl;

	return 0;

}
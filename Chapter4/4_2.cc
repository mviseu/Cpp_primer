#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
	const vector<int> vec = {4, 3, 2, 1};

	//member access has precedence over dereference operator
	cout << * (vec.begin()) << endl;

	//dereference operator has precedence over sum
	cout << * vec.begin() + 1 << endl;

	return 0;
}
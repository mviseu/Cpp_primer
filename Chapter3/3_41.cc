//intialize a vector from an array of ints
#include <iostream>
#include <vector>
#include <iterator>

using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::vector;

int main() {
	const int array[5] = {0, 1, 2, 3, 4};

	const vector<int>v1(begin(array), end(array));

	for(const auto &c : v1)
		cout << c << " ";

	cout << endl;

	return 0;
}
#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;

int main() {
	vector<int> vec = {0, 1, 2, 3};
	fill_n(vec.begin(), vec.size(), 0);

	for(const auto &e : vec) {
		cout << e << endl;
	}

	return 0;
}

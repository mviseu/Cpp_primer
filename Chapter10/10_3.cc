#include <numeric>
#include <vector>
#include <iostream>

using std::accumulate;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
	vector<int> vec = {0, 1, 2, 3};
	cout << accumulate(vec.cbegin(), vec.cend(), 0) << endl;
	return 0;
}
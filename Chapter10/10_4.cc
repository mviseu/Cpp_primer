#include <numeric>
#include <vector>
#include <iostream>

using std::accumulate;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
	vector<double> vec = {0, 0.1, 0.2, 0.3};
	//0.0 must be used since 3rd argument determines the type that is used in the sum
	//if 0 is used all the doubles would be converted to int to perform the sum
	cout << accumulate(vec.cbegin(), vec.cend(), 0.0) << endl;
	return 0;
}
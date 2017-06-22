#include <algorithm>
#include <vector>
#include <iostream>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
	vector<int> vec;
	int i;
	while(cin >> i) {
		vec.push_back(i);
	} 
	constexpr int iref = 42;
	cout << iref << " was counted " << count(vec.cbegin(), vec.cend(), iref) << " times" << endl;

	return 0;
}
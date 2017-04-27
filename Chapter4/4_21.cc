#include <iostream>
#include <vector>

using std::cin;
using std::endl;
using std::cout;
using std::vector;

int main() {
	vector<int> vec;
	int i;
	while(cin >> i) {
		vec.push_back(i) ;
	}

	cout << endl;
	for(auto &a : vec) {
		cout << (a % 2 == 1 ? a *= 2 :  a += 0) << " ";
	}

	cout << endl;

	return 0;
}

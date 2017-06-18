#include <vector>
#include <iostream>

using std::vector;
using std::endl;
using std::cout;


int main() {
	vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto iter = v.begin();
	while(iter != v.end()) {
		++iter;
		//when we insert a value before iter, iter becomes invalid
		iter = v.insert(iter, 42);
		++iter;
	}
	for(const auto &e : v) {
		cout << e << " ";
	}
	cout << endl;
	return 0;
}

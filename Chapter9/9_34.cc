#include <vector>
#include <iostream>

using std::vector;
using std::endl;
using std::cout;

int main() {
	vector<int> v = {0, 1, 2, 3};

	auto iter = v.begin();
	while(iter != v.end()) {
		if(*iter % 2) {
			++(iter = v.insert(iter, *iter));
		}
		++iter;
	}
	for(const auto &e : v) {
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
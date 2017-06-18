#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main() {
	vector<int> v;
	cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
	for(auto i = 0; i != 24; ++i) {
		v.push_back(i);
		cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
	}
	v.reserve(50);
	for(auto i = 24; i != 50; ++i) {
		v.push_back(i);
		cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
	}
	v.push_back(50);
	cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
	v.shrink_to_fit();
	return 0;
}
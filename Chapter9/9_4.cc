#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;


bool find(vector<int>::const_iterator beg, vector<int>::const_iterator end, int i) {
	while(beg != end) {
		if(*beg == i) {
			return true;
		}
		++beg;
	}
	return false;
}


int main() {
	vector<int> vec{1, 4, 8};
	cout << find(vec.cbegin(), vec.cend(), 3) << endl;
	return 0;
}
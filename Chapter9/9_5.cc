#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;


vector<int>::const_iterator find(vector<int>::const_iterator beg, vector<int>::const_iterator end, int i) {
	while(beg != end) {
		if(*beg == i) {
			return beg;
		}
		++beg;
	}
	return end;
}


int main() {
	vector<int> vec{1, 4, 8};
	if(find(vec.cbegin(), vec.cend(), 4) != vec.cend()) {
		cout << "The element is in the container" << endl;
	} else {
		cout << "The element is not in the container" << endl;
	}
	return 0;
}
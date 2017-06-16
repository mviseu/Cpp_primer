#include <vector>
#include <iostream>
#include <list>

using std::vector;
using std::cout;
using std::endl;
using std::list;

int main() {
	vector<int> v1 = {0, 1, 2, 3};
	list<int>	l1 = {0, 1, 2};

	if(v1.size() != l1.size()) {
		cout << "The vectors are not equal" << endl;
		return 0;
	} 

	auto iterV2 = l1.cbegin();
	for(auto iterV1 = v1.cbegin(); iterV1 != v1.cend(); ++iterV1, ++iterV2) {
		if(*iterV1 != *iterV2) {
			cout << "The vectors are not equal" << endl;
			return 0;
		}
	}

	cout << "The vectors are equal" << endl;
	return 0;

}
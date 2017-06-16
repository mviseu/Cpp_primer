#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main() {
	vector<int> v1 = {0, 1, 2};
	vector<int>	v2 = {0, 1, 3};

	if(v1 == v2) {
		cout << "The vectors are equal" << endl;
	} else {
		cout << "The vectors are not equal" << endl;
	}
	return 0;
}
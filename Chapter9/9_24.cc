#include <vector>
#include <iostream>
#include <stdexcept>

using std::vector;
using std::cout;
using std::endl;
using std::out_of_range;

int main() {
	vector<int> v1 = {1};
	int firstElement1{0}, firstElement2{0}, firstElement3{0}, firstElement4{0};

	if(!v1.empty()) {
	    firstElement1 = v1.front(), firstElement2 = v1[0], 
		firstElement3 = *v1.cbegin();
	}

	try {
		firstElement4 = v1.at(0);
	} catch(out_of_range err) {
		cout << "Error!" << err.what() << endl;

	}

	return 0;
}
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main() {
	//6 different ways to initialise a vector

	//default constructor
	vector<int>vecDefault; //empty vector

	//list initialization
	vector<int>vecList = {0, 1, 2, 3, 4, 5};

	//copy
	vector<int>vecCopy = vecList;

	//iterators
	vector<int>vecIter(vecList.cbegin(), vecList.cend());

	//size -> ints are value initialized to zero
	vector<int>vecSizeOnly(10);

	vector<int>vecSizeAndValue(10, 3);

	vector<vector<int>> all = {vecDefault, vecList, vecCopy, 
							vecIter, vecSizeOnly, vecSizeAndValue};

	for(const auto &v : all) {
		for(const auto &e : v) {
			cout << e << " ";
		}
		cout << endl;
	}

	return 0;
}
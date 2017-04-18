#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;


int main() {
	vector<vector<int>> ivec(5, {0, 1, 2});

	auto len = ivec.size();
	cout << "The size of the ivec vector is: " << len << endl;

	for(auto c : ivec) {
		cout << "The elements inside each vector are: " << endl;
		for (auto a: c) {
			cout << a << endl;
		}
	}

	//error: svec holds strings not vectors
	//vector<string> svec = ivec;

	vector<string> svec(10, "Null");
	auto lenVectorHoldsStrings = svec.size();

	cout << "The size of this vector is: " << lenVectorHoldsStrings << endl;

	for(auto c : svec) {
		cout << "Element of the string vector: " << c << endl;
	}


	return 0;

}
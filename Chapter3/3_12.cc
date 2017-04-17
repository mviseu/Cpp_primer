#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
	//This creates a vector of vectors of type int. Initialised to empty vector.
	vector<vector<int>> ivec(10, {2});
	//error: svec holds string not vectors that hold int
	//vector<string> svec = ivec; 

	//This should create a vector that holds 10 string instances "null"
	vector<string> svec(10, "null");

	for(auto &c : svec) {
		cout << c << endl;
	}

	for(auto &c : ivec) {
		for (auto &a : c) {
			cout << a << endl;
		}
	}

	return 0;
}


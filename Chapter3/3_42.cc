#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;



int main() {

	vector<int>vector{1, 2, 3, 4};
	int array[4] = {};

	//copy a vector of ints into an array of ints
	for(decltype(vector.size()) i = 0; i != vector.size(); ++i) {
		array[i] = vector[i]; 
	}


	for(const auto &c : array) {
		cout << c << " " ;
	}

	cout << endl;

	return 0;
}
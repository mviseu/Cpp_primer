#include <iostream>
#include <vector>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::vector;


int main() {
	//value initialized at 0
	int array1[4] = {1, 2, 3, 4};
	int array2[4] = {1, 2, 2, 4};

	//prompt the user for the array elements
	cout << "Please provide array 1 with 4 int elements" << endl;
	for (auto &c : array1) {
		if(cin >> c) {

		} else {
			cout << "input is not of type int" << endl;
			return -1;
		}
	}


	cout << "Please provide array 2 with 4 int elements" << endl;
	for (auto &c : array2) {
		if(cin >> c) {
			
		} else {
			cout << "input is not of type int" << endl;
			return -1;
		}
	}

	//compare
	for(size_t i = 0; i != 4; ++i) {
		if(array1[i] != array2[i]) {
			cout << "The arrays are NOT identical" << endl;
			return -1;
		}
		i = i + 1;
	}

	cout << "The arrays are identical!" << endl;
	return 0;
}


#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::end;


int main() {
	constexpr size_t size = 10;
	//will create an array of 10 ints with undefined value
	int array[size] ;
	int *pointer = array; //pointer to the first element of array

	//print the starting array elements
	for(const auto &c : array) {
		cout << c << " ";
	}

	cout << endl;
	//set all the elements in an array to zero

	for(auto pointer = array; pointer != end(array); ++pointer)
		*pointer = 0;

	//print the final elements
	for(const auto &c : array) {
		cout << c << " ";
	}

	return 0;
}
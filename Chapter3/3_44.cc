#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::begin;
using std::end;


int main() {


	const int ia[][4] = { {0, 1, 2, 3},
					     {4, 5, 6, 7},
					     {8, 9, 10, 11}
				   		 };



	constexpr size_t sizeRow = end(ia) - begin(ia), 
				 sizeColumn = end(ia[0]) - begin(ia[0]);



	using ArrayConstInt = const int [sizeColumn];
	using refToConstInt = const int &;
	using pointToConstInt = const int *;

	cout << "Using a range for to print the ia elements" << endl;


	for(ArrayConstInt &a : ia) {
		for(refToConstInt b : a) {
			cout << b << " ";
		}
		cout << endl;
	}
	

	cout << "Using subscripts to print the ia elements" << endl;
	for(size_t indexRow = 0; indexRow != sizeRow; ++indexRow) {

		for(size_t indexColumn = 0; indexColumn != sizeColumn; ++indexColumn) {
			cout << ia[indexRow][indexColumn] << " ";
		}

		cout << endl;
	}  


	cout << "Using pointers to print the ia elements" << endl;

	for(ArrayConstInt *p = ia; p != end(ia); ++p) {

		for(pointToConstInt q = *p; q != end(*p); ++q) {
			cout << *q << " ";
		}
		cout << endl;
	}

	return 0;

}
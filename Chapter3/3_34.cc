#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::begin;
using std::end;

int main() {

	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	const int *p1 = begin(array);
	const int *p2 = end(array);

	/* this will make p1 point to the same element as p2

	summarizing:
	begin(array) <= p1 <= end(array)

	begin(array) <= p2 <= end(array)
	*/


	p1 += p2 - p1;

	//testing

	if (p1 < end(array)) {
		cout << "new p1 is pointing to the element: " << *p1 << endl;
	} else {
		if (p1 == end(array)) {
			cout << "new p1 is the off-the-end pointer!" << endl;
		} else {
			cout << "error! New p1 across the array boundary (undefined)" << endl;
			return -1;
		}
	}


	return 0;
}
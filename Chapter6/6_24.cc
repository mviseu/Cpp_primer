#include <iostream>

using std::cout;
using std::endl;

//This is a pointer to the first element of ia. Points to a const int (read not write).
//[10] is irrelevant in the function declaration but gives indication on the dimension.
//p[n] is the same as *(p + n); 

void print(const int ia[10]) {

	for(size_t i = 0; i != 10; ++i) {
		cout << ia[i] << endl;
	}
}

int main() {
	//element 5 on are value initialized to zero
	const int array[10] = {0, 1, 2, 3};
	print(array);

	return 0;
}
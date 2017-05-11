#include <iostream>

using std::endl;
using std::cout;

//returns a reference to an int 
//array must exist after the function terminates therefore it was changed to &
int & get(int (&array) [10], int index) {
	return array[index];
}

int main() {

	int ia[10];

	for(int i = 0; i != 10; ++i) {
		//get returns an lvalue (&) which means it can be assigned
		//equivalent to ia[i] = i;
		get(ia, i) = i;
	}
	//compiler implicitly returns 0
}
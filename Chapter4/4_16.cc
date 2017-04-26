#include <iostream>

using std::cout;
using std::endl;

int main() {
	int i = 0;

	/* Assignment has low precedence so getPtr() != 0 is evaluated first

	if (p = getPtr() != 0) {

	} */

	//This always evaluates as true

	/*if(i = 42) {
		cout << "i is non zero so it evaluates as true!" << endl;
	} */

	if(i == 42) {
		cout << "Now I only evaluate as true if i is 42" << endl;
	}

	/*This would get a pointer and ensure that the condition is met if it is not null
	if((p = getPrt()) != 0) */


	return 0;
}
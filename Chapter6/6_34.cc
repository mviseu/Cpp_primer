#include <iostream>

using std::cout;
using std::endl;

int factorial(int val) {

	//can be val != 0 or val > 1. If val != 0 it calls factorial one more time
	if(val != 0) {
		//val-- instead of val - 1 returns val unchanged -> loop would be infinite
		//--val would have an evaluation order problem in factorial(--val) * val;
		return factorial(val-1) * val;
	}

	return 1;
}

int main() {
	cout << factorial(5) << endl;
}
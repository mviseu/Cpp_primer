#include <iostream>

using std::cout;
using std::endl;

//a
void f() {
	cout << "Function with no parameters" << endl;
}

//b
void f(int) {
	cout << "Function with 1 int parameter" << endl;
}

//c
void f(int, int){
	cout << "Function with 2 int parameters" << endl;
}

//d
void f(double, double = 3.14){
	cout << "Function with 2 double parameters" << endl;
}

int main() {

	/*functions that take 2 arguments (c,d) are viable
	It is an an ambiguous call since there is no best match
	2.56 would have to be converted to int or 42 to double
	f(2.56, 42);
	*/

	/* b and d are viable functions 
	d provides the remaining argument by default
	b is the best match since no implicit conversion is required
	*/
	f(42);

	/*c and d are viable functions
	c provides the best match since there is no conversion required
	d would require implicit converion from int to double*/
	f(42, 0);

	/*c and d are viable functions
	d provides the best match since there is no conversion required
	c would require implicit converion from double to int*/

	f(2.56, 3.14);
	
	return 0;
}
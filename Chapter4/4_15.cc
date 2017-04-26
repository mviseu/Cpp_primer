#include <iostream>

using std::cout;
using std::endl;

int main() {

	double dval;
	int ival;
	int *pi;

	/*the type int* cannot be converted to int in assignment ival = p. 

	dval = ival = pi = 0; */

	/*Alternative: First assign pi to null pointer
	*/

	pi = 0;
	dval = ival = 0;
	cout << dval << ival << pi << endl;


	return 0;
}
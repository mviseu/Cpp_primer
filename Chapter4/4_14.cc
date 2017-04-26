#include <iostream>

using std::cout;
using std::endl;

int main() {

	int i;

	/*Assignment requires a left hand lvalue operand so this is not allowed
	if (42 = i) {

	} */

	/* Assignment returns left hand operand lvalue, so it returns 42
	42 evaluates as true (any non zero does)
	if(true)
	*/
	if(i = 42) {
		cout << "This will evaluate as true since 42 is non-zero" << endl;

	}
	return 0;
}
#include <iostream>

using std::cout;
using std::endl;

int main() {

	constexpr bool someValue = true;
	int x = 10, y = 20;


	/* It someValue is true:
	- Increment x
	- Increment y 
	- Decrement y and return

	If someValue is false:
	- Decrement x
	- Decrement y and return */

	cout << ((someValue ? ++x, ++y : --x), --y) << endl;

	return 0;
}
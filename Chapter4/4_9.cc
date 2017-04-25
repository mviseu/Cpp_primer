#include <iostream>

using std::cout;
using std::endl;

int main() {
	//pointer to the first element of the string literal (it is null terminated)
	const char *cp = "Hello World";

	//if cp is NOT null pointer and the object to which it points to (the char) is NOT backslash 0
	if(cp && *cp) {
		cout << "Cp is not a null pointer and the element to which it points to is not zero!" << endl;
	}

	return 0;
}

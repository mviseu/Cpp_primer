#include <iostream>

using std::cout;
using std::endl;

int main() {
	const char ca[] = {'h', 'e', 'l', 'o'};
	//points to the first element of the array
	const char *cp = ca;
	//prints hello to the output
	// problem -> no null is appended and undefined behaviour will occur (print rubbish?)
	while(*cp) {
		cout << *cp << endl;
		++cp;
	}
	return 0;
}
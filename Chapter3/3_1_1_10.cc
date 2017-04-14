#include <iostream>

using std::cout;
using std::endl;

int main() {
	//cannot be unsigned otherwise the while loop will be infinite (negative value -1 would wrap around)
	int counter = 10;

	while (counter >= 0) {
		cout << counter << endl;
		--counter;
	}
	return 0;
}
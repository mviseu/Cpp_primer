#include <iostream>

using std::cout;
using std::endl;

int main() {

	int array[10] = {};
	size_t i = 0;

	for(auto &c : array) {
		c = i;
		cout << array[i] << endl;
		i = i + 1;
	}

	return 0;
}
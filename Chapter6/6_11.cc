#include <iostream>

using std::cout;
using std::endl;

inline void reset(int &c) {
	c = 0;
}

int main() {
	int i = 42;
	reset(i);
	cout << i << endl;
	return 0;
}
#include <iostream>

using std::cout;
using std::endl;

int main() {
	auto add = [](int i1, int i2) {return i1 + i2;};
	cout << add(1, 2) << endl;
	return 0;
}
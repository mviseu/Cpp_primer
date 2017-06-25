#include <iostream>

using std::cout;
using std::endl;


void enclose() {
	auto a = 42;
	auto l = [a](int b){return a + b;};
	cout << l(2) << endl;
}

int main() {
	enclose();
	return 0;
}
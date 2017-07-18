#include "HasPtr_13_30.h"
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

int main() {
	HasPtr ptr1("third"), ptr2("second"), ptr3("first");
	vector<HasPtr> vec = {ptr1, ptr2, ptr3};
	vec.resize(50, HasPtr("hello"));
	for(const auto &e : vec) {cout << e.get() << " ";}
	cout << endl;
	std::sort(vec.begin(), vec.end());
	for(const auto &e : vec) {cout << e.get() << " ";}
	return 0;
}
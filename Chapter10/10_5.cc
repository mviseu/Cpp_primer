#include <algorithm>
#include <iostream>
#include <vector>

using std::equal;
using std::cout;
using std::vector;
using std::endl;

int main() {
	vector<const char *>roster1 = {"Yes", "it", "is"};
	vector<const char *>roster2 = {"Yes", "it", "is"};
	//equal now compares the address of the pointers rather than the actual value of the element they point to
	cout << equal(roster1.cbegin(), roster1.cend(), roster2.cend()) << endl;
	return 0;
}
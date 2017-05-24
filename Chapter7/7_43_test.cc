#include "7_43.h"
#include <vector>

using std::vector;

int main() {
	C test;

	//value initialized vec requires a default constructor for initialization of its NoDefault elements;
	//not legal
	//vector<NoDefault> vec(10);

	//legal since there is a default constructor for C
	vector<C> vec(10);
	return 0;
}
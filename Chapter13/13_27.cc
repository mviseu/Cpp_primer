#include "13_27HasPtr.h"
#include <iostream>

using std::cout;
using std::endl;

	HasPtr hp1("Hello");
int main() {
	{
		HasPtr hp2(hp1);
		hp2 = hp2;
	}

	return 0;
}
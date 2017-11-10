#include "16_3.h"
#include "16_3_NoLessOperator.h"
#include <iostream>

int main() {
	int a = 0, b = 2;
	int * a_ptr = &a;
	int * b_ptr = &b;
	NoLessOperator c;
	NoLessOperator d;
	// compare address of 2 unrelated ptrs
	std::cout << compare(b, a) << std::endl;
	//Errors during instantiation
	//compare(c,d);
	return 0;
}

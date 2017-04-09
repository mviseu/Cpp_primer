#include <iostream>

int main() {

	int i = 42 ;
	//create a pointer that hold the address of i
	int *p1 = &i;
	//change value of object i. new value i = old value * old value
	*p1 = *p1 * *p1 ;
	std::cout << "This is the new i: " << i << std::endl;
	return 0;
}
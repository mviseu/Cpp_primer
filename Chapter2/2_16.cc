#include <iostream>
int main() {
	int i, &r1 = i;
	i = 5; 
	r1=10;
	std::cout << i << " " << r1 << std::endl;
	return 0;
}


#include <iostream>
int i = 42;
int main() {
	int i = 100 ;
	//j takes the value of local scope i
	int j = i;
	std::cout << j << std::endl;
	return 0;
}

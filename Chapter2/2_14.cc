#include <iostream>

int main() {
	int i = 100, sum = 0;
	for (int i = 0; i != 10; ++i) {
		sum += i;
		std::cout << "Inside the for loop " << i << " " << sum << std::endl;
	}	
	//i and sum will now be outside the scope of the for loop
	std::cout << "Outisde the for loop " << i << " " << sum << std::endl;
	return 0;
} 
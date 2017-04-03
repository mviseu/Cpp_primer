#include <iostream>

int main() {
	int v1 = 0, v2 = 0;
	std::cout << "Please provide 2 integers" << std::endl;
	std::cin >> v1 >> v2; 	// The user will give 2 numbers
	if (v1 < v2) {
		for (int i = v1; i <= v2; ++i) //Do not forget the semicolon between the init-statement, condition and expression!
			std::cout << i << std::endl;
	} 

	else {
		for (int i = v2; i <= v1; ++i) 
			std::cout << i << std::endl;
	}

	return 0;
}
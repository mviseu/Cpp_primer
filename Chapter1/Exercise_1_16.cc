#include <iostream>

int main()
{
	//Do not forget to initialise all variables
	int v1=0, sum=0;
	std::cout << "Please provide a set of input integers" << std::endl;
	while (std::cin >> v1) {
		sum += v1; //compound assign
		std::cout << "Current sum: " << sum << std::endl;

	}
	return 0;
}
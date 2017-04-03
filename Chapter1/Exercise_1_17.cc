#include <iostream>

int main()
{
	int v_old = 0, v_new = 0;
	if (std::cin >> v_old) {
		int counter = 1;
		while (std::cin >> v_new) {
			if (v_old == v_new)
				++counter; //prefix increment
			else {
				std::cout << "The number " << v_old << " repeats " 
				<< counter << " times!" << std::endl;
				counter = 1;
				v_old = v_new;
			}
		} //end of while loop
		std::cout << "The last number, " << v_old << ", repeats " 
				  << counter << " times!" << std::endl;
	} //end of outer if statement
	return 0;
}
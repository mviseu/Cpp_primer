#include "18_9_Sales_data.h"
#include <iostream>
#include <string>

int main() {
	Sales_data item1, item2, item3;
	while(std::cin >> item1 >> item2) {
		try {
			item3 = item1 + item2;
			std::cout << item3 << std::endl;
		}
		catch (const mismatch_isbn &mis) {
			std::cout << mis.what() 
					  << " left: " << mis.left
					  << " right: " << mis.right
					  << std::endl;
		}
	}

	/*while(std::cin >> item1 >> item2) {
			item3 = item1 + item2;
			std::cout << item3 << std::endl;
	}*/
	return 0;
}
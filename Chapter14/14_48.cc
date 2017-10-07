#include "14_48.h"
#include <iostream>

int main() {
	Book bk("Pride and Prejudice"), bk_empty;
	if(bk) {
		std::cout << "Book has a title" << std::endl;
	}
	if(!bk_empty) {
		std::cout << "Book does not have a title" << std::endl;
	}
	return 0;
}
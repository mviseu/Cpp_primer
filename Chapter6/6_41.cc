#include <iostream>

using std::cout;
using std::endl;

void init(int ht, int wd = 80, char background = ' ') {
	cout <<"height: " << ht << endl
		 << "width: " << wd << endl
		 << "background: " << background << endl;
}

int main() {
	//init is missing a ht specification
	//init();

	//ht will be 24, wd will be 10
	init(24, 10);

	//ht will be 14 and wd will be converted from char * to int 42!!
	init(14, '*');
	return 0;
}
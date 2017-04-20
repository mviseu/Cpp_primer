
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


int main() {
	unsigned buf_size = 1024; 
	//int ia[buf_size] ; /
	int iab[4 * 7 - 14] ;  //legal since dimension is a constexpr (integral literal)
	//char st[11] = "Fundamental"; //ilegal since dimension must encompass 11 characters + null = 12


	//print elements
	for(const auto &c : iab) {
		cout << c << endl;
	} 

	return 0;
}
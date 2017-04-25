#include <iostream>

using std::cout;
using std::endl;

int main() {

	constexpr int m = ((((12 / 3) * 4) + (5 * 15)) + ((24 % 4) / 2)) ;
	constexpr int n = 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2 ;

	cout << m << " " << n << endl;
	return 0;
}
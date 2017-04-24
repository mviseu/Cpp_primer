#include <iostream>

using std::cout;
using std::endl;

int main() {
	const int result = 5 + 10 * 20 / 2;

	/*order of precedence
	associativity from left to right
	10 * 20 = 200
	200 / 2 = 100
	5 + 100 = 105 */

	cout << result << endl; 
	return 0;
}
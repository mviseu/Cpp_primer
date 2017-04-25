#include <iostream>

using std::cout;
using std::endl;

int main() {
	constexpr int a = -30 * 3 + 21 / 5, a_p = (((-30) * 3) + (21 / 5)) ;
	cout << a << " " << a_p << endl;

	constexpr int b = -30 + 3 * 21 / 5, b_p = ((-30) + ((3 * 21) / 5)) ;
	cout << b << " " << b_p << endl;

	constexpr int c = 30 / 3  * 21 % 5, c_p = (((30 / 3)  * 21) % 5) ;
	cout << c << " " << c_p << endl;

	constexpr int d = -30 / 3 * 21 % 4, d_p = ((((-30) / 3) * 21) % 4) ;

	cout << d << " " << d_p << endl;

	return 0;
}

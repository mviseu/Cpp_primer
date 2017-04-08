#include <iostream>
int main() {
	int i = 0, &r1 = i;
	double d = 3.14, &r2 = d;

	r2 = r1;
	std::cout << "i:" << i << '\n'
			  << "r1:" << r1 << '\n'
  			  << "d:" << d << '\n'
			  << "r2:"<< r2 << std::endl;

	return 0;
}
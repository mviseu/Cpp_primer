#include <iostream>
#include <typeinfo>

using std::cout;
using std::endl;

int main() {
	int i = 2,j = 3;

	//j/i is division between to int which is truncated closest to zero
	//static cast converts result from int to double 
	double slope = static_cast<double>(j/i);

	cout << static_cast<double>(j/i) << endl;
	cout << typeid(static_cast<double>(j/i)).name() << endl;
	//same as not having the static_cast because the division is between ints
	//double slope = j/i;	

	return 0;
}
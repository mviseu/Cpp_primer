#include <string>
#include <map>
#include <functional>
#include <iostream>
#include <iterator>

int add(int a, int b) {	return a + b;}

auto subtract = std::minus<int>();

struct multiply {
	int operator() (int a, int b) {return a * b;}
};

auto divide = [] (int a, int b) {return a / b;};

int modulus(int a, int b) {	return a % b;}

int (* modulus_ptr) (int, int) = modulus;

int main() {
	std::map<std::string, std::function<int(int,int)>> desk_calc = {
		{"+", add},
		{"-", subtract},
		{"*", multiply()},
		{"/", divide},
		{"%", modulus}
	};

	std::ostream_iterator<int> out(std::cout, "\n");

	out = desk_calc["+"](1, 3);
	out = desk_calc["-"](3, 1);
	out = desk_calc["*"](3, 2);
	out = desk_calc["/"](6, 2);
	out = desk_calc["%"](12, 4);

	return 0;
}

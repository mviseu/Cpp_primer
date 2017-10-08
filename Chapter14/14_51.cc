#include <iostream>


struct LongDouble {
public:
	LongDouble(double d = 0.0) : val(d) {};
	operator double() const {return val;}
	operator float() const {return val;}

private:
	long double val = 0.0L;
};

void calc(int) {std::cout << "int argument function is called" << std::endl;}
void calc(LongDouble) {std::cout << "LongDouble argument function is called" << std::endl;}

int main() {
	double dval;
	//1st and best match is to convert double to int since it is a built-in conversion which is ranked above user-defined conversions
	calc(dval);
	//2nd and viable option is to convert double to LongDouble through the converting constructor
	return 0;
}
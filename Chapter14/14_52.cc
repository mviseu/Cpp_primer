#include <iostream>

struct SmallInt
{
public:
	SmallInt(int i = 0) : val(i) {
		if(i < 0 || i > 255) {
			throw std::out_of_range("Bad SmallInt value");
		}
	}
	operator int() const {return val;}

private:
	std::size_t val;
};

struct LongDouble {
public:
	LongDouble(double d = 0.0) : val(d){};
	operator double() const {return val;}
	operator float() const {return val;}
	LongDouble operator+(const SmallInt &si) {return si + val;}

private:
	long double val = 0.0L;
};

LongDouble operator+(LongDouble &ld, double d) {return ld + d;}


void calc(int) {std::cout << "int argument function is called" << std::endl;}
void calc(LongDouble) {std::cout << "LongDouble argument function is called" << std::endl;}

int main() {
	SmallInt si;
	LongDouble ld;
	// operator+ member function si cannot be used since rhs operand is SmallInt -> there is no path from ld to si (two user-defined conv.)
	// operator + non-member function can also not be used since lhs is ld and there is no conversion from si to ld
	// only option is built-in arithmetic operator+
	// ambigous 3, 4
	//3. si to int / long double ld to double / built-in + / double to long double assignment via constructor
	//4. si to int / long double to float /  build-int + / float to double / double to long double assignment via constructor
	//ld = si + ld;

	//exact match for member-function operator+ that takes si on rhs
	//other viable functions
	//si to int -> int to double -> non-member operator+
	//si to int -> ld to double/float -> arithmetic -> convertion back to ld after assignment via constructor
	ld = ld + si;

	double d = si + 3.14;

	return 0;
}
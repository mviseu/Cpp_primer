#include <iostream>

class Class {
public:
	Class() {std::cout << "Class()" << std::endl;}
};

class Base : public Class {
public:
	Base() {std::cout << "Base()" << std::endl;}
};

class D1 : virtual public Base {
public:
	D1() {std::cout << "D1()" << std::endl;}
};

class D2 : virtual public Base {
public:
	D2() {std::cout << "D2()" << std::endl;}
};

class MI : public D1, public D2 {
public:
	MI() {std::cout << "MI()" << std::endl;}
};

class Final : public MI, public Class {
public:
	Final() {std::cout << "Final()" << std::endl;}
};

int main() {
	Final f;
	// constructors
	// Class() -> indirect base from Final
	// Base()
	// D1()
	// D2()
	// MI()
	// Class() -> the direct base from Final
	// Final()

	// destructors on opposite order, i.e.:
	// Final()
	// Class() -> direct base
	// MI()
	// D2()
	// D1()
	// Base()
	// Class() -> indirect base

	// A final object has 1 Base subobject (Base is virtual base class)
	// A final object has 2 Class subobjects

	Base *pb;
	Class *pc;
	MI *pmi;
	D2 *pd2;

	// error: no derived-to-base conversion
	//pb = new Class;

	// Class has two subobjects -> ambiguous conversion from derived to base class
	//pc = new Final;

	// Base to derived conversion is not allowed
	// pmi = pb;

	// Normal derived to base conversion
	pd2 = pmi;
	return 0;
}
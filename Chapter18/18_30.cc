#include <iostream>

class Class {
public:
	Class() {std::cout << "Class()" << std::endl;}
};

class Base : public Class {
public:
	Base(const Base &rhs) {std::cout << "Base(const Base &rhs)" << std::endl;}
	Base() {std::cout << "Base()" << std::endl;}
	Base(int) {std::cout << "Base(int)" << std::endl;}
};

class D1 : virtual public Base {
public:
	D1() : Base() {std::cout << "D1()" << std::endl;}
	D1(const D1 &rhs) : Base(rhs) {std::cout << "D1(const D1 &rhs)" << std::endl;}
	D1(int i) : Base(i) {std::cout << "D1(int)" << std::endl;}
};

class D2 : virtual public Base {
public:
	D2() : Base() {std::cout << "D2()" << std::endl;}
	D2(const D2 &rhs) : Base(rhs) {std::cout << "D2(const D2 &rhs)" << std::endl;}
	D2(int i) : Base(i) {std::cout << "D2(int)" << std::endl;}
};

class MI : public D1, public D2 {
public:
	MI() : Base(), D1(), D2() {std::cout << "MI()" << std::endl;}
	MI(const MI &rhs) : Base(rhs), D1(rhs), D2(rhs) {std::cout << "MI(const MI &)" << std::endl;}
	MI(int i) : Base(i), D1(i), D2(i) {std::cout << "MI(int i)" << std::endl;}
};

class Final : public MI, public Class {
public:
	Final() : Base(), MI(), Class() {std::cout << "Final()" << std::endl;}
	Final(const Final &rhs) : Base(rhs), MI(rhs), Class() {std::cout << "Final(const Final &)" << std::endl;}
	Final(int i) : Base(i), MI(i), Class() {std::cout << "Final(int i)" << std::endl;}
};

int main() {
	std::cout << "Default" << std::endl;
	Final f1;
	std::cout << "Copy constructor" << std::endl;
	Final f2(f1);
	std::cout << "Int constructor" << std::endl;
	Final f3(1);
	return 0;
}
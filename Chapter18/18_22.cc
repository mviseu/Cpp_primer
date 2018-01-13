#include <iterator>
#include <iostream>
#include <string>

std::ostream_iterator<std::string> out(std::cout, "\n");

struct A {
	A() {out = "A()";}
};

struct B : public A {
	B() {out = "B()";}	
};

struct C : public B {
	C() {out = "C()";}
};

struct X {
	X() {out = "X()";}
};

struct Y {
	Y() {out = "Y()";}
};

struct Z : public X, public Y {
	Z() {out = "Z()";}
};

struct MI : public C, public Z {
	MI() {out = "MI()";}
};

int main() {
	//order: A, B, C, X, Y, Z
	MI m;
	return 0;
}
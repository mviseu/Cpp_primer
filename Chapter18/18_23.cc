#include <iterator>
#include <iostream>
#include <string>

std::ostream_iterator<std::string> out(std::cout, "\n");

class A {
public:
	A() {out = "A()";}
};

class B : public A {
public:
	B() {out = "B()";}	
};

class C : public B {
public:
	C() {out = "C()";}
};

class X {
public:
	X() {out = "X()";}
};

class D : public X, public C {
public:
	D() {out = "D()";}
};

int main() {
	// all conversions are permitted
	D *pd = new D;
	X *px = pd;
	A *pa = pd;
	B *pb = pd;
	C *pc = pd;
	return 0;
}
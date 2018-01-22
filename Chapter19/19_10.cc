#include <typeinfo>
#include <string>
#include <vector>
#include <iostream>

class A {
public:
	A() {}
	virtual ~A() {}
};

class B : public A {
public:
	B() : A() {}
	virtual ~B() {}
};

class C : public B {
public:
	C() : B() {}
	virtual ~C() {}
};

int main() {
	A *pa = new C;
	std::cout << typeid(pa).name() << std::endl;

	C cobj;
	A &ra = cobj;
	std::cout << typeid(&ra).name() << std::endl;


	B *px = new B;
	A &ra2 = *px;

	std::cout << typeid(ra2).name() << std::endl;
	return 0;
}
#include <iostream>
#include <typeinfo>

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

class D : public B, public A {
public:
	D() : B(), A() {}
	virtual ~D() {}
}; 

int main() {
	A *pa = new C;
	/*
	if(C *pc = dynamic_cast<C*>(pa)) {
		C &c_ref = *pc;
		// use C's members
	} else {
		// use A's members
	}
	*/

	try {
		C & c_ref= dynamic_cast<C&>(*pa);
		std::cout << "cast suceeded" << std::endl;	
	} catch (const std::bad_cast &bc) {
		std::cout << bc.what() << std::endl;
	}

	return 0;
}
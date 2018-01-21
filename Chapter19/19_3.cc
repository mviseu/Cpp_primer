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

class D : public B, public A {
public:
	D() : B(), A() {}
	virtual ~D() {}
}; 

int main() {
	{
		A *pa = new C;

		if(B *pb = dynamic_cast<B*>(pa)) {
			std::cout << "cast succeeded" << std::endl;
		}
	}

	{
		B *pb = new B;

		if(C *pc = dynamic_cast<C*>(pb)) {
		} else {
			std::cout << "cast failed" << std::endl;
		}
	}

/*
	{	// ambiguous conversion from derived class D to A
		A *pa = new D;

		if(B *pb = dynamic_cast<B*>(pa)) {
			std::cout << "cast succeeded" << std::endl;
		} else {
		}
	}
*/


	return 0;
}
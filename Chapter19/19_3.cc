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
	return 0;
}
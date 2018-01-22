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
	int i = 0;
	double d = 2.5;
	unsigned arr[4] = {0, 1, 2, 3}; 
	std::string s = "hello";
	std::vector<long> vl = {2, 3, 4};
	A *ptr_a = new C;
	const B &ref_b = C();

	std::cout << typeid(i).name() << std::endl;
	std::cout << typeid(d).name() << std::endl;
	std::cout << typeid(arr).name() << std::endl;
	std::cout << typeid(s).name() << std::endl;
	std::cout << typeid(vl).name() << std::endl;
	std::cout << typeid(ptr_a).name() << std::endl;
	std::cout << typeid(*ptr_a).name() << std::endl;
	std::cout << typeid(ref_b).name() << std::endl;

	return 0;
}
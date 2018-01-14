#include <iostream>

struct Base {
	void bar(int) {std::cout << "Base::bar" << std::endl;}
protected:
	int ival = 0;
};

struct Derived1 : virtual public Base {
	void bar(char) {std::cout << "Derived1::bar" << std::endl;}
	void foo(char) {std::cout << "Derived1::foo" << std::endl;}
protected:
	char cval = 'a';
};

struct Derived2 : virtual public Base {
	void foo(int) {std::cout << "Derived2::foo" << std::endl;}
protected:
	int ival = 1;
	char cval = 'b';
};

class VMI : public Derived1, public Derived2 {
// which members can be accessed without qualification from here
public:
	VMI() {
		// Derived2::ival
		std::cout << ival << std::endl;
		//cval will be ambiguous -> define own member
		std::cout << cval << std::endl;
		//foo will be ambiguous -> define own member
		foo(1);
		foo('a');
		// Derived1::bar
		bar('c');
	}
	void foo(int i) {Derived2::foo(i);}
	void foo(char c) {Derived1::foo(c);}
	char cval = Derived2::cval;
};

int main() {
	VMI();
	return 0;
}
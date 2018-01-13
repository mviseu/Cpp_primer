#include <iterator>
#include <iostream>
#include <string>

std::ostream_iterator<std::string> out(std::cout, "\n");


struct Base1 {
	virtual void test() const {
		out = "Base1 test";
	}
	virtual ~Base1() {out = "~Base1()";}
};

struct Base2 {
	virtual void test() const {
		out = "Base2 test";
	}
	virtual ~Base2() {out = "~Base2()";}
};

struct D1 : public Base1 {
	virtual void test() const override {
		out = "D1 test";
	}
	~D1() {out = "~D1()";}
};

struct D2 : public Base2 {
	virtual void test() const override {
		out = "D2 test";
	}
	~D2() {out = "~D2()";}
};

struct MI : public D1, public D2 {
	virtual void test() const override {
		out = "M1 test";
	}
	~MI() {out = "~MI()";}
};

int main() {
	//MI m;
	Base1 *pb1 = new MI;
	Base2 *pb2 = new MI;
	D1 *pd1 = new MI;
	D2 *pd2 = new MI;

	pb1 -> test();
	pd1 -> test();
	pd2 -> test();

	delete pb2;
	delete pd1;
	delete pd2;
	return 0;
}
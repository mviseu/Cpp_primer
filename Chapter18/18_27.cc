#include <iostream>
#include <iterator>
#include <string>
#include <vector>

std::ostream_iterator<std::string> out(std::cout, "\n");

struct Base1 {
    void print(int) const {
        out = "Base1 print(int)";
    };
protected:
    int ival;
    double dval;
    char cval = 'a';
private:
    int *id;
};

struct Base2 {
    void print(double) const {
        out = "Base2 print(double)";    	
    }
protected:
    double fval = 2.323;
private:
    double dval;
};

struct Derived : public Base1 {
	void print(std::string) const {
		out = "Derived print(std::string)";
	}
	void print(int i) const {
		Base1::print(i);
	}
	void set_sval_in_derived() {
		if(!sval.empty()) {
			sval[0] = Base1::cval;
		} else {
			sval.push_back(Base1::cval);
		}
		std::cout << sval[0] << std::endl;
	}
protected:
    std::string sval = "hello";
    double dval = 2.5;
};

struct MI : public Derived, public Base2 {
	void print(std::vector<double>) {
		out = "MI print(std::vector<double>)";
	}
	void print(int i) const {
		Derived::print(i);
	}
	void print(std::string s) const {
		Derived::print(s);
	}
	void print(double d) const {
		Base2::print(d);
	}
	void foo(double cval);

	void set_fval_in_base2() {
		if(!dvec.empty()) {
			Base2::fval = dvec.back();
			std::cout << fval << std::endl;
		}
	}
protected:
    int *ival;
    std::vector<double> dvec = {1.1, 3.3};
};

int ival = 4;
double dval = 2.0;

void MI::foo(double cval) {
	int dval = Base1::dval + Derived::dval;
	dvec;
	out = std::to_string(fval);
	print(std::string("hello"));
}

int main() {
	MI mi;
	mi.foo(1.0);
	// All names visible within MI::foo
	// All except private data members from base classes

	// Names visible from more than 1 base class
	// cval, ival, dval visible from more than 1 base class
	// print functions visible from 1 than 1 base class

	// Immediately visible names
	//MI::foo::dval;
	//MI::foo::cval;
	//MI::ival 
	//MI::dvec;
	//Derived::sval
	//Base2::fval
	//Base1::id NOT accessible (private in Base1)
	//MI::print functions

	mi.set_fval_in_base2();
	Derived d;
	d.set_sval_in_derived();

	return 0;
}
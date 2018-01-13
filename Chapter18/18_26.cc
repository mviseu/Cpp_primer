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
    char cval;
private:
    int *id;
};

struct Base2 {
    void print(double) const {
        out = "Base2 print(double)";    	
    }
protected:
    double fval;
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
protected:
    std::string sval;
    double dval;
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
protected:
    int *ival;
    std::vector<double> dvec;
};

int main() {
	MI mi;
	mi.print(2);
	mi.print(std::string());
	mi.print(2.0);
	return 0;
}
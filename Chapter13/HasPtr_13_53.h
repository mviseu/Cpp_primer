#pragma once
#include <string>
#include <iostream>

using std::string;

using std::cout;
using std::endl;

class HasPtr {
	friend void swap(HasPtr &lhs, HasPtr &rhs);
public:
	HasPtr(const string &s = string()) :
	ps(new string(s)), i(0) {}
	HasPtr(const HasPtr &hp) :
	ps(new string(*hp.ps)), i(hp.i) {cout << "Copy constructor" << endl;}
	HasPtr(HasPtr &&hp) noexcept;
	//HasPtr& operator=(HasPtr rhs);
	HasPtr& operator=(const HasPtr &rhs);
	HasPtr& operator=(HasPtr &&rhs) noexcept;
	bool operator<(const HasPtr &rhs) const {return *ps < *rhs.ps;}

	string get() const {return *ps;}
	~HasPtr();
private:
	string *ps;
	int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs) {
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	cout << "using swap non member function" << endl;
}

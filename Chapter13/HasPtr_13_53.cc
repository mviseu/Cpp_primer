#include "HasPtr_13_53.h"
#include <iostream>

using std::cout;
using std::endl;

HasPtr::HasPtr(HasPtr &&hp) noexcept : ps(hp.ps), i(hp.i) {
	hp.ps = nullptr;
	cout << "Move constructor" << endl;
}

HasPtr& HasPtr::operator=(const HasPtr &rhs) {
	auto str_copy = new string(*rhs.ps);
	delete ps;
	ps = str_copy;
	i = rhs.i;
	cout << "Copy assignment" << endl;
	return *this;
}

HasPtr& HasPtr::operator=(HasPtr &&rhs) noexcept {
	if(&rhs != this) {
		delete ps;
		ps = rhs.ps;
		i = rhs.i;
		rhs.ps = nullptr;
	}
	cout << "Move assignment" << endl;
	return *this;
}

/*HasPtr& HasPtr::operator=(HasPtr rhs) {
	swap(*this, rhs);
	return *this;
}*/


HasPtr::~HasPtr() {
	delete ps;
	cout << "Destructor" << endl;
}
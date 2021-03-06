#include "HasPtr.h"

HasPtr& HasPtr::operator=(const HasPtr &rhs) {
	auto str_copy = new string(*rhs.ps);
	delete ps;
	ps = str_copy;
	i = rhs.i;
	return *this;
}

HasPtr::~HasPtr() {
	delete ps;
}
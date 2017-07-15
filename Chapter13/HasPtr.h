#pragma once
#include <string>

using std::string;

class HasPtr {
public:
	HasPtr(const string &s = string()) :
	ps(new string(s)), i(0) {}
	HasPtr(const HasPtr &hp) :
	ps(new string(*hp.ps)), i(hp.i) {}
	HasPtr& operator=(const HasPtr &rhs) {
		if(ps) {
			delete ps;
		}
		ps = new string(*rhs.ps);
		i = rhs.i;
		return *this;
	}
private:
	string *ps;
	int i;
};
#pragma once
#include <string>

using std::string;

class HasPtr {
public:
	HasPtr(const string &s = string()) :
	ps(new string(s)), i(0), use(new int(1)) {}


	HasPtr(const HasPtr &hp) :
	ps(hp.ps), i(hp.i), use(hp.use) {++*use;}


	HasPtr& operator=(const HasPtr &rhs);
	~HasPtr();
private:
	string *ps;
	int i;
	int *use;
};
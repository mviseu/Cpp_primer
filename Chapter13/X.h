#pragma once
#include <iostream>

using std::cout;
using std::endl;

struct X {
	X() {cout << "X()" << endl;}
	X(const X &x) {cout << "X(const X &)" << endl;}
	X& operator =(const X &rhs) {
		cout << "X& operator =(const X &)" << endl;
		return *this;
	}
	~X() {cout << "~X()" << endl;}
};
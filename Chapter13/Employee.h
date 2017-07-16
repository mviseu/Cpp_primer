#pragma once
#include <string>

using std::string;

class Employee {
public:
	string name;
	int identifier = 0;
	Employee() : identifier(ctr++) {}
	Employee(const string &nm) : name(nm), identifier(ctr++) {}
	Employee(const Employee &em) = delete;
	Employee &operator=(const Employee &rhs) = delete;

private:
	static int ctr;
};
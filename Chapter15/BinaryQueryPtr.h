#pragma once 
#include "QueryPtr.h"
#include <string>
#include <iostream>

class BinaryQueryPtr : public BaseQueryPtr {
protected:
	BinaryQueryPtr(const QueryPtr &l, const QueryPtr &r, const std::string &s) : lhs(l), rhs(r), sym(s) {std::cout << "BinaryQuery constructor" << std::endl;}
	std::string rep() const {std::cout << "BinaryQuery rep" << std::endl; return "(" + lhs.rep() + " " + sym + " " + rhs.rep() + ")";}
	QueryPtr lhs, rhs;
	std::string sym;
};
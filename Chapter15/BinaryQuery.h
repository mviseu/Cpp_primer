#pragma once 
#include "Query.h"
#include <string>
#include <iostream>

class BinaryQuery : public BaseQuery {
protected:
	BinaryQuery(const Query &l, const Query &r, const std::string &s) : lhs(l), rhs(r), sym(s) {std::cout << "BinaryQuery constructor" << std::endl;}
	std::string rep() const {std::cout << "BinaryQuery rep" << std::endl; return "(" + lhs.rep() + " " + sym + " " + rhs.rep() + ")";}
	Query lhs, rhs;
	std::string sym;
};
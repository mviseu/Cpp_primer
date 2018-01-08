#pragma once 
#include "18_8_Query.h"
#include <string>
#include <iostream>

class BinaryQuery : public BaseQuery {
protected:
	BinaryQuery(const Query &l, const Query &r, const std::string &s) noexcept(false) : lhs(l), rhs(r), sym(s) {
		#ifdef VERBOSE
			std::cout << "BinaryQuery constructor" << std::endl;
		#endif
	}
	std::string rep() const {
		#ifdef VERBOSE
			std::cout << "BinaryQuery rep" << std::endl; 
		#endif
		return "(" + lhs.rep() + " " + sym + " " + rhs.rep() + ")";
	}
	Query lhs, rhs;
	std::string sym;
};
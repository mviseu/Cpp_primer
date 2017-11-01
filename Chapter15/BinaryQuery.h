#pragma once 
#include "Query.h"
#include <string>

class BinaryQuery : public BaseQuery {
protected:
	BinaryQuery(const Query &l, const Query &r, const std::string &s) : lhs(l), rhs(r), sym(s) {}	
	std::string rep() const {return "(" + lhs.rep() + " " + sym + " " + rhs.rep() + ")";}
	Query lhs, rhs;
	std::string sym;
};
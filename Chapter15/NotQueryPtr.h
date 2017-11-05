#pragma once
#include "QueryPtr.h"
#include "BaseQueryPtr.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include <string>
#include <iostream>

class NotQueryPtr : public BaseQueryPtr {
	friend QueryPtr operator~(const QueryPtr &qr);
	NotQueryPtr(const QueryPtr &q) : qr(q) {std::cout << "NotQuery constructor" << std::endl;}	
	QueryResult eval(const TextQuery &tq) const;
	std::string rep() const {std::cout << "NotQuery rep" << std::endl; return "~ (" + qr.rep() + ")";}
	QueryPtr qr;
};	
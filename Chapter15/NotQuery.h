#pragma once
#include "Query.h"
#include "BaseQuery.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include <string>
#include <iostream>

class NotQuery : public BaseQuery {
	friend Query operator~(const Query &qr);
	NotQuery(const Query &q) : qr(q) {std::cout << "NotQuery constructor" << std::endl;}	
	QueryResult eval(const TextQuery &tq) const;
	std::string rep() const {std::cout << "NotQuery rep" << std::endl; return "~ (" + qr.rep() + ")";}
	Query qr;
};	
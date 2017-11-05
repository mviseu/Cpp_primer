#pragma once
#include "QueryPtr.h"
#include "BinaryQueryPtr.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include <iostream>
#include <string>

class AndQueryPtr : public BinaryQueryPtr {
	friend QueryPtr operator&(const QueryPtr &lhs, const QueryPtr &rhs);
	AndQueryPtr(const QueryPtr &lhs, const QueryPtr &rhs) : BinaryQueryPtr(lhs, rhs, "&") {std::cout << "AndQuery constructor" << std::endl;}
	QueryResult eval(const TextQuery &tq) const;	
};
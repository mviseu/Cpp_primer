#pragma once
#include "QueryPtr.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include "BinaryQueryPtr.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include <iostream>

class OrQueryPtr : public BinaryQueryPtr {
	friend QueryPtr operator|(const QueryPtr &lhs, const QueryPtr &rhs);
	OrQueryPtr(const QueryPtr &lhs, const QueryPtr &rhs) : BinaryQueryPtr(lhs, rhs, "|") {std::cout << "OrQuery constructor" << std::endl;}
	QueryResult eval(const TextQuery &tq) const;
};
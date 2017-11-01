#pragma once
#include "Query.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include "BinaryQuery.h"

class OrQuery : public BinaryQuery {
	friend Query operator|(const Query &lhs, const Query &rhs);
	OrQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "|") {}
	QueryResult eval(const TextQuery &tq) const;
};
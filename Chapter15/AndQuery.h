#pragma once
#include "Query.h"
#include "BinaryQuery.h"
#include "TextQuery.h"
#include "QueryResult.h"

#include <string>

class AndQuery : public BinaryQuery {
	friend Query operator&(const Query &lhs, const Query &rhs);
	AndQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "&") {}
	QueryResult eval(const TextQuery &tq) const;	
};
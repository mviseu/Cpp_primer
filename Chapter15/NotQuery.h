#pragma once
#include "Query.h"
#include "BaseQuery.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include <string>

class NotQuery : public BaseQuery {
friend Query operator~(const Query &qr);
	NotQuery(const Query &q) : qr(q) {}	
	QueryResult eval(const TextQuery &tq) const;
	std::string rep() const {return "~ (" + qr.rep() + ")";}
	Query qr;
};	
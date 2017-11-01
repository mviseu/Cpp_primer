#pragma once
#include "BaseQuery.h"
#include "QueryResult.h"
#include <string>

class WordQuery : public BaseQuery {
	friend class Query;
	WordQuery(const std::string &wd) : word(wd) {}

	QueryResult eval(const TextQuery &tq) const {return tq.query(word);}
	std::string rep() const { return word; }

	std::string word;
};
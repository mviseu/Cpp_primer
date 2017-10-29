#pragma once
#include <string>
#include <vector>

#include "QueryResult.h"
#include "TextQuery.h"

class BaseQuery {
friend class Query;
protected:
	using line_no = std::vector<std::string>::size_type;
	virtual ~BaseQuery() = default;
private:
	virtual QueryResult eval(const TextQuery&) const = 0;
	virtual std::string rep() const = 0;

};
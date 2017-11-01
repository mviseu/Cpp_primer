#pragma once
#include <string>
#include <vector>
#include <iostream>

#include "QueryResult.h"
#include "TextQuery.h"

class BaseQuery {
friend class Query;
protected:
	BaseQuery() {std::cout << "BaseQuery default constructor" << std::endl;}
	using line_no = std::vector<std::string>::size_type;
	virtual ~BaseQuery() = default;
private:
	virtual QueryResult eval(const TextQuery&) const = 0;
	virtual std::string rep() const = 0;

};
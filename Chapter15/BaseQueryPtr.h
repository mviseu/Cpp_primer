#pragma once
#include <string>
#include <vector>
#include <iostream>

#include "QueryResult.h"
#include "TextQuery.h"
#include "QueryPtr.h"

class BaseQueryPtr {
friend class QueryPtr;
protected:
	BaseQueryPtr() {std::cout << "BaseQuery default constructor" << std::endl;}
	using line_no = std::vector<std::string>::size_type;
	virtual ~BaseQueryPtr() = default;
private:
	virtual QueryResult eval(const TextQuery&) const = 0;
	virtual std::string rep() const = 0;

};
#pragma once
#include <string>
#include <vector>
#include <iostream>

#include "19_6_QueryResult.h"
#include "19_6_TextQuery.h"


class BaseQuery {
friend class Query;
protected:
	BaseQuery() noexcept {
		#ifdef VERBOSE
			std::cout << "BaseQuery default constructor" << std::endl;
		#endif
	}
	using line_no = std::vector<std::string>::size_type;
	virtual ~BaseQuery() noexcept = default;
private:
	virtual QueryResult eval(const TextQuery &, line_no, line_no) const = 0;
	virtual std::string rep() const = 0;

};
#pragma once
#include "19_6_Query.h"
#include "19_6_BinaryQuery.h"
#include "19_6_TextQuery.h"
#include "19_6_QueryResult.h"
#include <iostream>
#include <string>

class AndQuery : public BinaryQuery {
	friend Query operator&(const Query &lhs, const Query &rhs);
	AndQuery(const Query &lhs, const Query &rhs) noexcept(false) : BinaryQuery(lhs, rhs, "&") {
		#ifdef VERBOSE
			std::cout << "AndQuery constructor" << std::endl;
		#endif
	}
	QueryResult eval(const TextQuery &tq, line_no range_start, line_no range_end) const;	
};
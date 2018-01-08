#pragma once
#include "18_8_Query.h"
#include "18_8_BinaryQuery.h"
#include "18_8_TextQuery.h"
#include "18_8_QueryResult.h"
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
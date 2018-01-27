#pragma once
#include "19_20_Query.h"
#include "19_20_TextQuery.h"
#include "19_20_BinaryQuery.h"
#include <iostream>


class OrQuery : public BinaryQuery {
	friend Query operator|(const Query &lhs, const Query &rhs);
	OrQuery(const Query &lhs, const Query &rhs) noexcept(false) : BinaryQuery(lhs, rhs, "|") {
		#ifdef VERBOSE
			std::cout << "OrQuery constructor" << std::endl;
		#endif
	}
	TextQuery::QueryResult eval(const TextQuery &tq, line_no range_start, line_no range_end) const;
};

#pragma once
#include "18_8_Query.h"
#include "18_8_BaseQuery.h"
#include "18_8_TextQuery.h"
#include "18_8_QueryResult.h"
#include <string>
#include <iostream>

namespace chapter18 {

class NotQuery : public BaseQuery {
	friend Query operator~(const Query &qr);
	NotQuery(const Query &q) noexcept(noexcept(Query(q))): qr(q) {
		#ifdef VERBOSE
			std::cout << "NotQuery constructor" << std::endl;
		#endif
	}	
	QueryResult eval(const TextQuery &tq, line_no range_start, line_no range_end) const;
	std::string rep() const {
		#ifdef VERBOSE
			std::cout << "NotQuery rep" << std::endl; 
		#endif
		return "~ (" + qr.rep() + ")";
	}
	Query qr; 
};

} // namespace chapter8
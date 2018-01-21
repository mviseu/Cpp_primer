#pragma once
#include "19_6_Query.h"
#include "19_6_BaseQuery.h"
#include "19_6_TextQuery.h"
#include "19_6_QueryResult.h"
#include <string>
#include <iostream>


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

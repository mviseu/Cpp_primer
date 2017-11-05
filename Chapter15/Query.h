#pragma once
#include "WordQuery.h"
#include "BaseQuery.h"
#include "QueryResult.h"
#include "TextQuery.h"

#include <memory>
#include <string>
#include <iostream>

class Query {

friend Query operator~(const Query &qr);
friend Query operator|(const Query &lhs, const Query &rhs);
friend Query operator&(const Query &lhs, const Query &rhs);
using line_no = std::vector<std::string>::size_type;

public:
	Query(const std::string &wd) : qr(new WordQuery(wd)) {
		#ifdef VERBOSE
			std::cout << "Query string constructor" << std::endl;
		#endif
	}
	QueryResult eval(const TextQuery &tq, line_no range_start, line_no range_end) const {
		#ifdef VERBOSE
			std::cout << "Query eval" << std::endl;
		#endif
		return qr -> eval(tq, range_start, range_end);
	}
	std::string rep() const {
		#ifdef VERBOSE
			std::cout << "Query rep" << std::endl;
		#endif 
		return qr -> rep();
	}

private:
	Query(const std::shared_ptr<BaseQuery> &ptr) : qr(ptr) {
		#ifdef VERBOSE
			std::cout << "Query shared_ptr constructor" << std::endl;
		#endif
	}
	std::shared_ptr<BaseQuery> qr;

};

Query operator~(const Query &qr);
Query operator|(const Query &lhs, const Query &rhs);
Query operator&(const Query &lhs, const Query &rhs);

std::ostream &operator<<(std::ostream &os, const Query &q);
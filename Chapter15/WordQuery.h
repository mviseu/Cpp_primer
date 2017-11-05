#pragma once
#include "BaseQuery.h"
#include "QueryResult.h"
#include <string>
#include <iostream>

class WordQuery : public BaseQuery {
	friend class Query;
	WordQuery(const std::string &wd) : word(wd) {
		#ifdef VERBOSE
			std::cout << "WordQuery constructor" << std::endl;
		#endif
	}

	QueryResult eval(const TextQuery &tq, line_no range_start, line_no range_end) const {
		#ifdef VERBOSE
			std::cout << "WordQuery eval" << std::endl; 
		#endif
		return tq.query(word, range_start, range_end);
	}
	std::string rep() const {
		#ifdef VERBOSE
			std::cout << "WordQuery rep" << std::endl; 
		#endif
		return word; 
	}

	std::string word;
};
  
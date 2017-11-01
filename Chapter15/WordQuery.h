#pragma once
#include "BaseQuery.h"
#include "QueryResult.h"
#include <string>
#include <iostream>

class WordQuery : public BaseQuery {
	friend class Query;
	WordQuery(const std::string &wd) : word(wd) {std::cout << "WordQuery constructor" << std::endl;}

	QueryResult eval(const TextQuery &tq) const {std::cout << "WordQuery eval" << std::endl; return tq.query(word);}
	std::string rep() const {std::cout << "WordQuery rep" << std::endl; return word; }

	std::string word;
};
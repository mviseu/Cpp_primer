#pragma once
#include "BaseQueryPtr.h"
#include "QueryResult.h"
#include <string>
#include <iostream>

class WordQueryPtr : public BaseQueryPtr {
	friend class QueryPtr;
	WordQueryPtr(const std::string &wd) : word(wd) {std::cout << "WordQuery constructor" << std::endl;}

	QueryResult eval(const TextQuery &tq) const {std::cout << "WordQuery eval" << std::endl; return tq.query(word);}
	std::string rep() const {std::cout << "WordQuery rep" << std::endl; return word; }

	std::string word;
};
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

public:
	Query(const std::string &wd) : qr(new WordQuery(wd)) {std::cout << "Query string constructor" << std::endl;}
	QueryResult eval(const TextQuery &tq) const {std::cout << "Query eval" << std::endl; return qr -> eval(tq);}
	std::string rep() const {std::cout << "Query rep" << std::endl; return qr -> rep();}

private:
	Query(const std::shared_ptr<BaseQuery> &ptr) : qr(ptr) {std::cout << "Query shared_ptr constructor" << std::endl;}
	std::shared_ptr<BaseQuery> qr;

};

Query operator~(const Query &qr);
Query operator|(const Query &lhs, const Query &rhs);
Query operator&(const Query &lhs, const Query &rhs);

std::ostream &operator<<(std::ostream &os, const Query &q);
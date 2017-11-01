#pragma once
#include "WordQuery.h"
#include "BaseQuery.h"
#include "QueryResult.h"
#include "TextQuery.h"

#include <memory>
#include <string>

class Query {

friend Query operator~(const Query &qr);
friend Query operator|(const Query &lhs, const Query &rhs);
friend Query operator&(const Query &lhs, const Query &rhs);

public:
	Query(const std::string &wd) : qr(new WordQuery(wd)) {}
	QueryResult eval(const TextQuery &tq) const {return qr -> eval(tq);}
	std::string rep() const {return qr -> rep();}

private:
	Query(const std::shared_ptr<BaseQuery> &ptr) : qr(ptr) {}
	std::shared_ptr<BaseQuery> qr;

};

Query operator~(const Query &qr);
Query operator|(const Query &lhs, const Query &rhs);
Query operator&(const Query &lhs, const Query &rhs);
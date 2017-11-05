#pragma once
#include "WordQueryPtr.h"
#include "BaseQueryPtr.h"
#include "QueryResult.h"
#include "TextQuery.h"

#include <string>
#include <iostream>

class QueryPtr {

friend QueryPtr operator~(const QueryPtr &qr);
friend QueryPtr operator|(const QueryPtr &lhs, const QueryPtr &rhs);
friend QueryPtr operator&(const QueryPtr &lhs, const QueryPtr &rhs);

public:
	QueryPtr(const std::string &wd) : qr(new WordQueryPtr(wd)),  use_count(new std::size_t(1)) {}

	QueryPtr(const QueryPtr &rhs) : qr(rhs.qr), use_count(rhs.use_count) {++*use_count;}
	QueryPtr(QueryPtr &&rhs) noexcept: qr(rhs.qr), use_count(rhs.use_count) {rhs.qr = nullptr; rhs.use_count = nullptr;}

	~QueryPtr() {
		if(!--*use_count) {
			delete qr;
			delete use_count;
		}
	}
	QueryPtr &operator=(const QueryPtr &rhs) {
		if(this != &rhs) {
			if(!--*use_count) {
				delete qr;
				delete use_count;
			}
			qr = rhs.qr;
			use_count = rhs.use_count;
			++*use_count;
		}
		return *this;
	}
	QueryPtr &operator=(QueryPtr &&rhs) noexcept {
		if(this != &rhs) {
			if(!--*use_count) {
				delete qr;
				delete use_count;
			}
			qr = rhs.qr;
			use_count = rhs.use_count;
			rhs.qr = nullptr;
			rhs.use_count = nullptr;
		}
		return *this;
	}

	QueryResult eval(const TextQuery &tq) const {return qr -> eval(tq);}
	std::string rep() const {return qr -> rep();}

private:
	QueryPtr(BaseQueryPtr * &&ptr) : qr(ptr),  use_count(new std::size_t(1)) {ptr = nullptr;}
	BaseQueryPtr *qr = nullptr;
	std::size_t *use_count = nullptr;

};

QueryPtr operator~(const QueryPtr &qr);
QueryPtr operator|(const QueryPtr &lhs, const QueryPtr &rhs);
QueryPtr operator&(const QueryPtr &lhs, const QueryPtr &rhs);

std::ostream &operator<<(std::ostream &os, const QueryPtr &q);
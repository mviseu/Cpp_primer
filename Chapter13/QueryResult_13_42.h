#pragma once
#include <memory>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include "StrVec.h"

using std::shared_ptr;
using std::string;
using std::set;
using std::map;
using std::vector;
using std::ostream;

class QueryResult {
	friend ostream &print(ostream &os, const QueryResult& qr);
public:
	using SetIter = set<size_t>::iterator;
	QueryResult(string wd, shared_ptr<StrVec> p_text, shared_ptr<set<size_t>> ptr_wd_line_nrs);
	SetIter begin() const;
	SetIter end() const;


private:
	string sought;
	shared_ptr<StrVec> file;
	shared_ptr<set<size_t>> lines;
};
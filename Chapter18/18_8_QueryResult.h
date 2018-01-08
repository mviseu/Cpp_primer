#pragma once
#include <memory>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <utility>
#include "18_8_StrBlob.h"

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
	QueryResult(string wd, StrBlob p_text, shared_ptr<set<size_t>> ptr_wd_line_nrs) noexcept(false);
	SetIter begin() const;
	SetIter end() const;
	shared_ptr<StrBlob> get_file() const;


private:
	string sought;
	StrBlob file;
	shared_ptr<set<size_t>> lines;
};
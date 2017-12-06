#pragma once
#include <memory>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include "16_30_StrBlob.h"
#include "16_28_SharedPtr.h"

using std::string;
using std::set;
using std::map;
using std::vector;
using std::ostream;

class QueryResult {
	friend ostream &print(ostream &os, const QueryResult& qr);
public:
	using SetIter = set<size_t>::iterator;
	QueryResult(string wd, StrBlob p_text, SharedPtr<set<size_t>> ptr_wd_line_nrs);
	SetIter begin() const;
	SetIter end() const;
	SharedPtr<StrBlob> get_file() const;

private:
	string sought;
	StrBlob file;
	SharedPtr<set<size_t>> lines;
};

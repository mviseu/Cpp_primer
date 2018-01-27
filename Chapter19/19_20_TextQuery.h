#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <set>
#include <map>
#include "19_20_StrBlob.h"
#include <iostream>

using std::ifstream;
using std::ostream;
using std::vector;
using std::string;
using std::shared_ptr;
using std::set;
using std::map;

class TextQuery
{
public:
	class QueryResult;
	TextQuery(ifstream &input) noexcept(false);
	QueryResult query(const string &word, std::size_t range_start, std::size_t range_end) const;

private:
	StrBlob file;
	map<string, shared_ptr<set<size_t>>> wm;
	void printMap();
	
};

class TextQuery::QueryResult {
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

ostream &print(ostream &os, const TextQuery::QueryResult &qr);
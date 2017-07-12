#pragma once
#include <memory>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>

using std::shared_ptr;
using std::string;
using std::set;
using std::map;
using std::vector;
using std::ostream;


class QueryResult {
	friend ostream &print(ostream &os, const QueryResult& qr);
public:
	QueryResult(string wd, shared_ptr<vector<string>>p_text, shared_ptr<set<size_t>> ptr_wd_line_nrs);

private:
	string word;
	shared_ptr<vector<string>> ptr_text;
	shared_ptr<set<size_t>> ptr_word_line_nrs;
};
#pragma once
#include <memory>
#include <string>
#include <set>
#include <map>

using std::shared_ptr;
using std::string;
using std::set;
using std::map;

class TextQuery;

class QueryResult {
	QueryResult(shared_ptr<TextQuery> sptr, string wd);

private:
	shared_ptr<TextQuery> tq_ptr;
	string word;
	int word_count;
	map<set<int>, string> &line_nr_text;

};
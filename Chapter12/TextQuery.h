#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <set>
#include <map>

using std::ifstream;
using std::vector;
using std::string;
using std::shared_ptr;
using std::set;
using std::map;

class QueryResult;

class TextQuery
{
	friend class QueryResult;
public:
	TextQuery(ifstream &input);

private:
	shared_ptr<vector<string>> lines;
	map<string, shared_ptr<set<int>>> map_word_ptr_line_nr;
	void buildMap();
	void printMap();
	
};
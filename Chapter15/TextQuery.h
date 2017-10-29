#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <set>
#include <map>
#include "StrBlob.h"

using std::ifstream;
using std::vector;
using std::string;
using std::shared_ptr;
using std::set;
using std::map;

class QueryResult;

class TextQuery
{
public:
	TextQuery(ifstream &input);
	QueryResult query(const string &word) const;

private:
	StrBlob file;
	map<string, shared_ptr<set<size_t>>> wm;
	void printMap();
	
};
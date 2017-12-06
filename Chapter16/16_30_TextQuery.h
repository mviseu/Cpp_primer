#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <set>
#include <map>
#include "16_30_StrBlob.h"
#include "16_28_SharedPtr.h"

using std::ifstream;
using std::vector;
using std::string;
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
	map<string, SharedPtr<set<size_t>>> wm;
	void printMap();
	
};

#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <set>
#include <map>
#include "17_3_StrBlob.h"
#include "17_3_TupleResult.h"

using std::ifstream;
using std::vector;
using std::string;
using std::shared_ptr;
using std::set;
using std::map;


class TextQuery
{
public:
	TextQuery(ifstream &input);
	Result query(const string &word) const;

private:
	StrBlob file;
	map<string, shared_ptr<set<size_t>>> wm;
	void printMap();
	
};
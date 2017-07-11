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

class TextQuery
{
public:
	TextQuery(ifstream &input);

private:
	shared_ptr<vector<string>> lines;
	map<string, set<int>> map_word_line_nr;
	void buildMap();
	void printMap();
	
};
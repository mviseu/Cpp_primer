#include "TextQuery.h"
#include "QueryResult.h"
#include <sstream>
#include <fstream>
#include <memory>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <utility>

using std::istringstream;
using std::ifstream;
using std::make_shared;
using std::copy;
using std::back_inserter;
using std::istream_iterator;
using std::cout;
using std::endl;
using std::make_pair;

TextQuery::TextQuery(ifstream &input) : lines(make_shared<vector<string>>()) {

	for(string line; getline(input, line); ) {
		lines -> push_back(line);
		auto i = lines -> size() - 1;
		istringstream input_line((*lines)[i]);
		string word;
		while(input_line >> word) {
			map_word_ptr_line_nr.insert(make_pair(word, new set<size_t>()));
			map_word_ptr_line_nr[word] -> insert(i);
		}

	}
}

void TextQuery::printMap() {
	for(const auto &pair : map_word_ptr_line_nr) {
		cout << pair.first << " ";

		for(const auto &i : *pair.second) {
			cout << i << " ";
		}
		cout << endl;
	}
}

QueryResult TextQuery::query(const string &word) const {
	auto ret = map_word_ptr_line_nr.find(word);
	if(ret == map_word_ptr_line_nr.end()) {
		return QueryResult(word, lines, make_shared<set<size_t>>());
	} else {
		return QueryResult(word, lines, ret -> second);
	}
}
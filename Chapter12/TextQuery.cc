#include "TextQuery.h"
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
	for(string line; getline(input, line); lines -> push_back(line));
	buildMap();
	printMap();
}

void TextQuery::buildMap() {
	for(size_t i = 0; i != lines -> size(); ++i) {
		istringstream line((*lines)[i]);
		string word;
		while(line >> word) {
			map_word_ptr_line_nr.insert(make_pair(word, new set<int>()));
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

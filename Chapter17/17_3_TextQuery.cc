#include "17_3_TextQuery.h"
#include "17_3_StrBlob.h"
#include <sstream>
#include <fstream>
#include <memory>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <utility>
#include <tuple>

using std::istringstream;
using std::ifstream;
using std::make_shared;
using std::copy;
using std::back_inserter;
using std::istream_iterator;
using std::cout;
using std::endl;
using std::make_pair;

TextQuery::TextQuery(ifstream &input) : file() {

	for(string line; getline(input, line); ) {
		file.push_back(line);
		auto i = file.size() - 1;
		istringstream input_line((*file.get())[i]);
		string word;
		while(input_line >> word) {
			wm.insert(make_pair(word, new set<size_t>()));
			wm[word] -> insert(i);
		}

	}
}

void TextQuery::printMap() {
	for(const auto &pair : wm) {
		cout << pair.first << " ";

		for(const auto &i : *pair.second) {
			cout << i << " ";
		}
		cout << endl;
	}
}

Result TextQuery::query(const string &word) const {
	auto ret = wm.find(word);
	if(ret == wm.end()) {
		return std::make_tuple(word, file, make_shared<set<size_t>>());
	} else {
		return std::make_tuple(word, file, ret -> second);
	}
}
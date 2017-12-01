#include "16_22_TextQuery.h"
#include "16_22_QueryResult.h"
#include "16_22_StrBlob.h"
#include <sstream>
#include <fstream>
#include <memory>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <utility>
#include "DebugDelete.h"

using std::istringstream;
using std::ifstream;
using std::make_shared;
using std::copy;
using std::back_inserter;
using std::istream_iterator;
using std::cout;
using std::endl;
using std::make_pair;

TextQuery::TextQuery(ifstream &input) {
	for(string line; getline(input, line); ) {
		file.push_back(line);
		auto i = file.size() - 1;
		istringstream input_line((*file.get())[i]);
		string word;
		while(input_line >> word) {
			std:: cout << "Before" << std::endl;
			wm.insert(make_pair(word, std::shared_ptr<set<size_t>>(new set<size_t>(), DebugDelete())));
			std:: cout << "After" << word << std::endl;
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

QueryResult TextQuery::query(const string &word) const {
	auto ret = wm.find(word);
	if(ret == wm.end()) {
		return QueryResult(word, file, std::shared_ptr<set<size_t>>(new set<size_t>(), DebugDelete()));
	} else {
		return QueryResult(word, file, ret -> second);
	}
}

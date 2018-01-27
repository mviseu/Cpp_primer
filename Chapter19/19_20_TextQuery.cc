#include "19_20_TextQuery.h"
#include "19_20_StrBlob.h"
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

TextQuery::QueryResult TextQuery::query(const string &word, std::size_t range_start, std::size_t range_end) const noexcept(false) {
	auto ret = wm.find(word);
	if(ret == wm.end()) {
		return QueryResult(word, file, make_shared<set<size_t>>());
	} else {
		auto lines_ptr = std::make_shared<std::set<std::size_t>>((*ret-> second).lower_bound(range_start - 1),
																((*ret->second).upper_bound(range_end - 1)));
		return QueryResult(word, file, lines_ptr);
	}
}

TextQuery::QueryResult::QueryResult(string wd, StrBlob p_text, shared_ptr<set<size_t>> ptr_wd_line_nrs) 
					    noexcept(false) : sought(wd), file(p_text), lines(ptr_wd_line_nrs) {
}

ostream &print(ostream &os, const TextQuery::QueryResult &qr) {
	os << qr.sought << " occurs " << qr.lines -> size() 
	   << (qr.lines -> size() != 1 ? " times" : " time") << endl;
	for(const auto &i : *qr.lines) {
		os << "(line " << i + 1 << ") " << (*(qr.file.get()))[i] << endl;
	}
	return os;
}

TextQuery::QueryResult::SetIter TextQuery::QueryResult::begin() const {
	return lines -> begin();
}
TextQuery::QueryResult::SetIter TextQuery::QueryResult::end() const {
	return lines -> end();
}

shared_ptr<StrBlob> TextQuery::QueryResult::get_file() const {
	return make_shared<StrBlob>(file);
}
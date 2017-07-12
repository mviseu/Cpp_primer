#include "QueryResult.h"
#include <memory>
#include <string>
#include <set>
#include <vector>
#include <iostream>

using std::shared_ptr;
using std::string;
using std::set;
using std::map;
using std::vector;
using std::ostream;
using std::endl;


QueryResult::QueryResult(string wd, shared_ptr<vector<string>>p_text, shared_ptr<set<size_t>> ptr_wd_line_nrs) 
					    : word(wd), ptr_text(p_text), ptr_word_line_nrs(ptr_wd_line_nrs) {
}

ostream &print(ostream &os, const QueryResult &qr) {
	os << qr.word << " occurs " << qr.ptr_word_line_nrs -> size() 
	   << (qr.ptr_word_line_nrs -> size() != 1 ? " times" : " time") << endl;
	for(const auto &i : *qr.ptr_word_line_nrs) {
		os << "(line " << i + 1 << ") " << (*qr.ptr_text)[i] << endl;
	}
	return os;
}

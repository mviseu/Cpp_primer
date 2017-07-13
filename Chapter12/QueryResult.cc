#include "QueryResult.h"
#include "StrBlob.h"
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
using std::make_shared;


QueryResult::QueryResult(string wd, StrBlob p_text, shared_ptr<set<size_t>> ptr_wd_line_nrs) 
					    : word(wd), ptr_text(p_text), ptr_word_line_nrs(ptr_wd_line_nrs) {
}

ostream &print(ostream &os, const QueryResult &qr) {
	os << qr.word << " occurs " << qr.ptr_word_line_nrs -> size() 
	   << (qr.ptr_word_line_nrs -> size() != 1 ? " times" : " time") << endl;
	for(const auto &i : *qr.ptr_word_line_nrs) {
		os << "(line " << i + 1 << ") " << (*(qr.ptr_text.get()))[i] << endl;
	}
	return os;
}

QueryResult::SetIter QueryResult::begin() const {
	return ptr_word_line_nrs -> begin();
}
QueryResult::SetIter QueryResult::end() const {
	return ptr_word_line_nrs -> end();
}

shared_ptr<StrBlob> QueryResult::get_file() const {
	return make_shared<StrBlob>(ptr_text);
}
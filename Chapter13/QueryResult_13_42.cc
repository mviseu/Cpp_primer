#include "QueryResult_13_42.h"
#include "StrVec.h"
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


QueryResult::QueryResult(string wd, shared_ptr<StrVec> p_text, shared_ptr<set<size_t>> ptr_wd_line_nrs) 
					    : sought(wd), file(p_text), lines(ptr_wd_line_nrs) {
}

ostream &print(ostream &os, const QueryResult &qr) {
	os << qr.sought << " occurs " << qr.lines -> size() 
	   << (qr.lines -> size() != 1 ? " times" : " time") << endl;
	for(const auto &i : *qr.lines) {
		os << "(line " << i + 1 << ") " << *((qr.file)-> begin() + i) << endl;
	}
	return os;
}

QueryResult::SetIter QueryResult::begin() const {
	return lines -> begin();
}
QueryResult::SetIter QueryResult::end() const {
	return lines -> end();
}
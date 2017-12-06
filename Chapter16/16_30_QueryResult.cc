#include "16_30_QueryResult.h"
#include "16_30_StrBlob.h"

#include <memory>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include "DebugDelete.h"

using std::string;
using std::set;
using std::map;
using std::vector;
using std::ostream;
using std::endl;


QueryResult::QueryResult(string wd, StrBlob p_text, SharedPtr<set<size_t>> ptr_wd_line_nrs) 
					    : sought(wd), file(p_text), lines(ptr_wd_line_nrs) {
}

ostream &print(ostream &os, const QueryResult &qr) {
	os << qr.sought << " occurs " << qr.lines -> size() 
	   << (qr.lines -> size() != 1 ? " times" : " time") << endl;
	for(const auto &i : *qr.lines) {
		os << "(line " << i + 1 << ") " << (*(qr.file.get()))[i] << endl;
	}
	return os;
}

QueryResult::SetIter QueryResult::begin() const {
	return lines -> begin();
}
QueryResult::SetIter QueryResult::end() const {
	return lines -> end();
}

SharedPtr<StrBlob> QueryResult::get_file() const {
	return SharedPtr<StrBlob>(new StrBlob(file));
}

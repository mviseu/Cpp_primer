#include "17_3_TupleResult.h"

#include "17_3_StrBlob.h"
#include <memory>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <tuple>
#include <map>

using std::shared_ptr;
using std::string;
using std::set;
using std::map;
using std::vector;
using std::ostream;
using std::endl;
using std::make_shared;

ostream &print(ostream &os, const Result &qr) {
	os << std::get<0>(qr) << " occurs " << std::get<2>(qr) -> size() 
	   << (std::get<2>(qr) -> size() != 1 ? " times" : " time") << endl;
	for(const auto &i : *std::get<2>(qr)) {
		os << "(line " << i + 1 << ") " << (*(std::get<1>(qr).get()))[i] << endl;
	}
	return os;
}

SetIter begin(const Result &res) {
	return std::get<2>(res) -> begin();
}

SetIter end(const Result &res) {
	return std::get<2>(res) -> end();
}

std::shared_ptr<StrBlob> get_file(const Result &res) {
	return std::make_shared<StrBlob>(std::get<1>(res));
}
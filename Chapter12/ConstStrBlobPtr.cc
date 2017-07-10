#include <memory>
#include <string>
#include <vector>
#include "ConstStrBlobPtr.h"
#include "StrBlob_const.h"
#include <stdexcept>

using std::shared_ptr;
using std::weak_ptr;
using std::string;
using std::vector;
using std::out_of_range;
using std::runtime_error;
using std::size_t;


ConstStrBlobPtr::ConstStrBlobPtr(const StrBlob &sptr, size_t i) : wkpr(sptr.data), curr(i) {}

shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t i, const string &mess) const {
	auto sptr = wkpr.lock();
	if(!sptr) {
		throw runtime_error("Unbound StrBlobPtr");
	}
	if(i >= sptr -> size()) {
		throw out_of_range(mess);
	}
	return sptr;
}

string &ConstStrBlobPtr::deref() const {
	auto sptr = check(curr, "Dereference past end");
	return (*sptr)[curr];
}


ConstStrBlobPtr &ConstStrBlobPtr::incr() {
	auto sptr = check(curr, "Incremented past end");
	++curr;
	return *this;
}
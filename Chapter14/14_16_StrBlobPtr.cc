#include <memory>
#include <string>
#include <vector>
#include "14_16_StrBlobPtr.h"
#include "14_16_StrBlob.h"
#include <stdexcept>

using std::shared_ptr;
using std::weak_ptr;
using std::string;
using std::vector;
using std::out_of_range;
using std::runtime_error;
using std::size_t;


StrBlobPtr:: StrBlobPtr(StrBlob &sptr, size_t i) : wkpr(sptr.data), curr(i) {}

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &mess) const {
	auto sptr = wkpr.lock();
	if(!sptr) {
		throw runtime_error("Unbound StrBlobPtr");
	}
	if(i >= sptr -> size()) {
		throw out_of_range(mess);
	}
	return sptr;
}

string &StrBlobPtr::deref() const {
	auto sptr = check(curr, "Dereference past end");
	return (*sptr)[curr];
}


StrBlobPtr &StrBlobPtr::incr() {
	auto sptr = check(curr, "Incremented past end");
	++curr;
	return *this;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	if(lhs.wkpr.lock() && rhs.wkpr.lock()) {
		return *lhs.wkpr.lock() == *rhs.wkpr.lock() && lhs.curr == rhs.curr;
	}
	//includes nullptr case
	return lhs.wkpr.lock() == rhs.wkpr.lock() && lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return !(rhs == lhs);
}
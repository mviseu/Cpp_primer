#include <memory>
#include <string>
#include <vector>
#include "14_30_StrBlobPtrConst.h"
#include "14_30_StrBlobConst.h"
#include <stdexcept>

using std::shared_ptr;
using std::weak_ptr;
using std::string;
using std::vector;
using std::out_of_range;
using std::runtime_error;
using std::size_t;


ConstStrBlobPtr::ConstStrBlobPtr(const ConstStrBlob &sptr, size_t i) : wkpr(sptr.data), curr(i) {}

shared_ptr<const vector<string>> ConstStrBlobPtr::check(size_t i, const string &mess) const {
	auto sptr = wkpr.lock();
	if(!sptr) {
		throw runtime_error("Unbound StrBlobPtr");
	}
	if(i >= sptr -> size()) {
		throw out_of_range(mess);
	}
	return sptr;
}

const string &ConstStrBlobPtr::do_deref() const {
  auto sptr = check(curr, "Dereference past end");
  return (*sptr)[curr];
}

const string &ConstStrBlobPtr::deref() const {
  return do_deref();
}

const string &ConstStrBlobPtr::operator*() const {
  return do_deref();
}

const string *ConstStrBlobPtr::operator->() const {
  return & this -> operator*();
}


ConstStrBlobPtr &ConstStrBlobPtr::incr() {
	auto sptr = check(curr, "Incremented past end");
	++curr;
	return *this;
}
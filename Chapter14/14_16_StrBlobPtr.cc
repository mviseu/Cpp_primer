#include <memory>
#include <string>
#include <vector>
#include "14_16_StrBlobPtr.h"
#include "14_16_StrBlob.h"
#include <stdexcept>
#include <iostream>

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


StrBlobPtr &StrBlobPtr::operator+=(int i) {
	curr += i;
	auto curr_lower = curr - 1;
	i > 0 ? check(curr_lower, "Iterator arithmetic past the off-the-end") : check(curr, "Iterator arithmetic before start");
	return *this;
}

StrBlobPtr &StrBlobPtr::operator-=(int i) {
	return *this += -i;
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

const char &StrBlobPtr::operator[](std::size_t i) const {
	return do_subscript(i);
}

char &StrBlobPtr::operator[](std::size_t i) {
	return do_subscript(i);
}

StrBlobPtr &StrBlobPtr::operator++() {
	check(curr, "incremented past end");
	++curr;
	return *this;
}

StrBlobPtr &StrBlobPtr::operator--() {
	--curr;
	check(curr, "decremented past begin");
	return *this;
}

StrBlobPtr StrBlobPtr::operator++(int) {
	auto ret = *this;
	++*this;
	return ret;
}

StrBlobPtr StrBlobPtr::operator--(int) {
	auto ret = *this;
	--*this;
	return ret;
}

char &StrBlobPtr::do_subscript(std::size_t i) const {
	auto sptr = check(curr, "Dereference past end");
	return const_cast<char &>((*sptr)[curr][i]);
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	//meaning equality = same underlying string
	auto lhs_ptr = lhs.check(lhs.curr, "Dereference past end");
	auto rhs_ptr = rhs.check(rhs.curr, "Dereference past end");
	return (*lhs_ptr)[lhs.curr] == (*rhs_ptr)[rhs.curr];
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return !(rhs == lhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	//meaning equality = same underlying string
	auto lhs_ptr = lhs.check(lhs.curr, "Dereference past end");
	auto rhs_ptr = rhs.check(rhs.curr, "Dereference past end");
	return (*lhs_ptr)[lhs.curr] < (*rhs_ptr)[rhs.curr];
}

bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return rhs < lhs;
}

bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return !(lhs < rhs);
}

bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return !(rhs < lhs);
}

StrBlobPtr operator+(const StrBlobPtr &lhs, int i) {
	StrBlobPtr ret = lhs;
	return ret += i;
}

StrBlobPtr operator-(const StrBlobPtr &lhs, int i) {
	StrBlobPtr ret = lhs;
	return ret += -i;
}

int operator-(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return lhs.curr - rhs.curr;
}

/*missing
//conversion from int to StrBlobPtr
subtracting two iterators
*/

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


StrBlobPtr &StrBlobPtr::operator+=(size_t i) {
	curr += i;
	check(++curr, "Iterator arithmetic past the off-the-end");
	return *this;
}

StrBlobPtr &StrBlobPtr::operator-=(size_t i) {
	curr += -i;
	check(curr, "Iterator arithmetic past the beginning");
	return *this;
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

StrBlobPtr operator+(const StrBlobPtr &lhs, size_t i) {
	StrBlobPtr ret = lhs;
	ret += i;
	return ret;
}

StrBlobPtr operator-(const StrBlobPtr &lhs, size_t i) {
	StrBlobPtr ret = lhs;
	ret += -i;
	return ret;
}

//missing
/* int for += with check function
subtracting two iterators
*/

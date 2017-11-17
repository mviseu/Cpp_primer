#include <memory>
#include <string>
#include <vector>
#include "16_12_BlobPtr.h"
#include "16_12_Blob.h"
#include <stdexcept>
#include <iostream>

using std::shared_ptr;
using std::weak_ptr;
using std::string;
using std::vector;
using std::out_of_range;
using std::runtime_error;
using std::size_t;


BlobPtr:: BlobPtr(Blob &sptr, size_t i) : wkpr(sptr.data), curr(i) {}

shared_ptr<vector<string>> BlobPtr::check(size_t i, const string &mess) const {
	auto sptr = wkpr.lock();
	if(!sptr) {
		throw runtime_error("Unbound BlobPtr");
	}
	if(i >= sptr -> size()) {
		throw out_of_range(mess);
	}
	return sptr;
}


BlobPtr &BlobPtr::operator+=(int i) {
	curr += i;
	auto curr_lower = curr - 1;
	i > 0 ? check(curr_lower, "Iterator arithmetic past the off-the-end") : check(curr, "Iterator arithmetic before start");
	return *this;
}

BlobPtr &BlobPtr::operator-=(int i) {
	return *this += -i;
}

string &BlobPtr::deref() const {
	auto sptr = check(curr, "Dereference past end");
	return (*sptr)[curr];
}


BlobPtr &BlobPtr::incr() {
	auto sptr = check(curr, "Incremented past end");
	++curr;
	return *this;
}

const char &BlobPtr::operator[](std::size_t i) const {
	return do_subscript(i);
}

char &BlobPtr::operator[](std::size_t i) {
	return do_subscript(i);
}

BlobPtr &BlobPtr::operator++() {
	check(curr, "incremented past end");
	++curr;
	return *this;
}

BlobPtr &BlobPtr::operator--() {
	--curr;
	check(curr, "decremented past begin");
	return *this;
}

BlobPtr BlobPtr::operator++(int) {
	auto ret = *this;
	++*this;
	return ret;
}

BlobPtr BlobPtr::operator--(int) {
	auto ret = *this;
	--*this;
	return ret;
}

char &BlobPtr::do_subscript(std::size_t i) const {
	auto sptr = check(curr, "Dereference past end");
	return const_cast<char &>((*sptr)[curr][i]);
}

bool operator==(const BlobPtr &lhs, const BlobPtr &rhs) {
	//meaning equality = same underlying string
	auto lhs_ptr = lhs.check(lhs.curr, "Dereference past end");
	auto rhs_ptr = rhs.check(rhs.curr, "Dereference past end");
	return (*lhs_ptr)[lhs.curr] == (*rhs_ptr)[rhs.curr];
}

bool operator!=(const BlobPtr &lhs, const BlobPtr &rhs) {
	return !(rhs == lhs);
}

bool operator<(const BlobPtr &lhs, const BlobPtr &rhs) {
	//meaning equality = same underlying string
	auto lhs_ptr = lhs.check(lhs.curr, "Dereference past end");
	auto rhs_ptr = rhs.check(rhs.curr, "Dereference past end");
	return (*lhs_ptr)[lhs.curr] < (*rhs_ptr)[rhs.curr];
}

bool operator>(const BlobPtr &lhs, const BlobPtr &rhs) {
	return rhs < lhs;
}

bool operator>=(const BlobPtr &lhs, const BlobPtr &rhs) {
	return !(lhs < rhs);
}

bool operator<=(const BlobPtr &lhs, const BlobPtr &rhs) {
	return !(rhs < lhs);
}

BlobPtr operator+(const BlobPtr &lhs, int i) {
	BlobPtr ret = lhs;
	return ret += i;
}

BlobPtr operator-(const BlobPtr &lhs, int i) {
	BlobPtr ret = lhs;
	return ret += -i;
}

int operator-(const BlobPtr &lhs, const BlobPtr &rhs) {
	return lhs.curr - rhs.curr;
}

/*missing
//conversion from int to BlobPtr
subtracting two iterators
*/

#include "StrVec.h"
#include <string>
#include <utility>

using std::string;
using std::pair;
using std::uninitialized_copy;

allocator<string> StrVec::alloc;

StrVec::StrVec(const StrVec &v) {
	auto ret = alloc_n_copy(v.begin(), v.end());
	element = ret.first;
	first_free = cap = ret.second;
}

StrVec &StrVec::operator=(const StrVec &rhs) {
	auto ret = alloc_n_copy(rhs.element, rhs.first_free);
	free();
	element = ret.first;
	first_free = cap = ret.second;
	return *this;
}

StrVec::~StrVec() {
	free();
}

void StrVec::push_back(const string &s) {
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

pair<string *, string *>StrVec::alloc_n_copy(const string *b, const string *e) {
	auto ret = alloc.allocate(e - b);
	return {ret, uninitialized_copy(b, e, ret)};
}

void StrVec::chk_n_alloc() {
	if(size() == capacity()) {
		reallocate();
	}
}

void StrVec::free() {
	if(element) {
		while(first_free != element) {
			alloc.destroy(--first_free);
		}
		alloc.deallocate(element, cap - element);
	}
}

void StrVec::reallocate() {
	auto new_size = (size() ? size() * 2 : 1) ;
	auto ret = (size() ? alloc.allocate(size() * 2) : alloc.allocate(1));
	auto elem = element;
	auto dest = ret;
	for(size_t i = 0; i != size(); ++i) {
		alloc.construct(dest++, std::move(*elem++));
	}
	free();
	element = ret;
	first_free = dest;
	cap = element + new_size;
}
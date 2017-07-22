#include "StrVec.h"
#include <string>
#include <utility>
#include <iostream>

using std::string;
using std::pair;
using std::uninitialized_copy;
using std::endl;
using std::cout;


allocator<string> StrVec::alloc;


StrVec::StrVec(initializer_list<string> il) {
	initialize_alloc_n_copy(il.begin(), il.end());
}

StrVec::StrVec(const StrVec &v) {
	initialize_alloc_n_copy(v.begin(), v.end());
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

void StrVec::resize(size_t new_size) {
	while(first_free > element + new_size) {
		alloc.destroy(--first_free);
	}
	while(first_free < element + new_size) {
		push_back(string());
	}
}

void StrVec::reserve(size_t min_capacity) {
	while(cap < element + min_capacity) {
		reallocate_capacity();
	}
}

void StrVec::push_back(const string &s) {
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

pair<string *, string *>StrVec::alloc_n_copy(const string *b, const string *e) {
	auto ret = alloc.allocate(e - b);
	return {ret, uninitialized_copy(b, e, ret)};
}

void StrVec::initialize_alloc_n_copy(const string *b, const string *e) {
	auto ret = alloc_n_copy(b, e);
	element = ret.first;
	first_free = cap = ret.second;
}

void StrVec::chk_n_alloc() {
	if(size() == capacity()) {
		reallocate_size();
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

void StrVec::reallocate_size() {
	reallocate(size());
}

void StrVec::reallocate_capacity() {
	reallocate(capacity());
}

void StrVec::reallocate(size_t n) {
	auto new_capacity = (n ? n * 2 : 1) ;
	auto ret = alloc.allocate(new_capacity);
	auto elem = element;
	auto dest = ret;
	for(size_t i = 0; i != size(); ++i) {
		alloc.construct(dest++, std::move(*elem++));
	}
	free();
	element = ret;
	first_free = dest;
	cap = element + new_capacity;
}

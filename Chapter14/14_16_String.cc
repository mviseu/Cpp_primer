#include "14_16_String.h"
#include <memory>
#include <algorithm>
#include <utility>

using std::pair;
using std::uninitialized_copy;


String::String(const String &s) {
	auto data = alloc_n_copy(s.begin(), s.end());
	element = data.first;
	first_free = cap = data.second;
	cout << "copy constructor" << endl;
}

String::String(const char *b) {
	size_t n = 0;
	for(; *b != '\0'; ++b, ++n);
	auto data = alloc_n_copy(b - n, b);
	element = data.first;
	first_free = cap = data.second;
}

String::String(String &&s) noexcept : 
	element(s.element), first_free(s.first_free), cap(s.cap) 
{
	s.first_free = s.cap = s.element = nullptr;
	cout << "move-constructor" << endl;
}

String &String::operator=(const String &s) {
	auto data = alloc_n_copy(s.begin(), s.end());
	free();
	element = data.first;
	first_free = cap = data.second;
	cout << "copy-assignment" << endl;
	return *this;
}

String &String::operator=(String &&s) noexcept {
	if(this != &s) {
		free();
		element = s.element;
		first_free = s.first_free;
		cap = s.cap;
		s.first_free = s.cap = s.element = nullptr;
	}
	cout << "move-assignment" << endl;
	return *this;
}

const char &String::operator[](std::size_t i) const {
	return element[i];
}

char &String::operator[](std::size_t i) {
	return element[i];
}

void String::push_back(char c) {
	reallocate_if_needed();
	alloc.construct(first_free++, c);
}

pair<char *, char *> String::alloc_n_copy(const char* b, const char* e) {
	auto elem = alloc.allocate(e - b);
	return {elem, uninitialized_copy(b, e, elem)};
}

void String::free() {
	if(element) {
		std::for_each(element, first_free, [this](const char c) {alloc.destroy(&c);});
		alloc.deallocate(element, cap - element);
	}
}

void String::reallocate_if_needed() {
	if(capacity() == size()) {reallocate();}
}

void String::reallocate() {
	auto new_capacity = (size() ? size() * 2 : 1);
	auto new_elem = alloc.allocate(new_capacity);
	auto dest = new_elem;
	auto copy_old_elem = element;
	while(dest != new_elem + size()) {
		alloc.construct(dest++, std::move(*copy_old_elem++));
	}
	alloc.deallocate(element, cap - element);
	element = new_elem;
	first_free = dest; 
	cap = element + new_capacity;
}

allocator<char> String::alloc; 

bool operator==(const String &lhs, const String &rhs) {
	return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

bool operator!=(const String &lhs, const String &rhs) {
	return !(lhs == rhs);
}
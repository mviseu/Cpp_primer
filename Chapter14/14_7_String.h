#pragma once
#include <memory>
#include <utility>
#include <iostream>

using std::allocator;
using std::pair;
using std::cout;
using std::endl;
using std::ostream;


class String {
public:
	String() {cout << "default constructor" << endl;}
	String(const String &s);
	String(const char *b);
	String(String &&s) noexcept;
	String &operator=(const String &);
	String &operator=(String &&s) noexcept;
	~String() {free(); cout << "destructor" << endl;}
	
	void push_back(char c);
	size_t size() const {return first_free - element;}
	size_t capacity() const {return cap - element;}
	char *begin() const {return element;}
	char *end() const {return first_free;}

private:
	pair<char *, char *> alloc_n_copy(const char* b, const char* e);
	void free();
	void reallocate();
	void reallocate_if_needed();
	char *element = nullptr;
	char *first_free = nullptr;
	char *cap = nullptr;
	static allocator<char> alloc; 
};

ostream &operator<<(ostream &os, const String &S);

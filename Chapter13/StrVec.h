#pragma once
#include <string>
#include <memory>
#include <utility>

using std::allocator;
using std::string;
using std::pair;

class StrVec {
public:
	StrVec() : element(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec &);
	StrVec &operator=(const StrVec &);
	~StrVec();
	void push_back(const string &s);
	size_t size() const {return first_free - element;}
	size_t capacity() const {return cap - element;}
	string *begin() const {return element;}
	string *end() const {return first_free;}


private:
	pair<string *, string *> alloc_n_copy(const string *b, const string *e);
	void chk_n_alloc();
	void reallocate();
	void free();

	//why does it need to be static?
	static allocator<string> alloc;
	string * element;
	string * first_free;
	string * cap;
};
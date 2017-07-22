#pragma once
#include <string>
#include <memory>
#include <utility>
#include <initializer_list>

using std::allocator;
using std::string;
using std::pair;
using std::initializer_list;

class StrVec {
public:
	StrVec() : element(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec &);
	StrVec(initializer_list<string> il);
	StrVec &operator=(const StrVec &);
	~StrVec();
	void push_back(const string &s);
	size_t size() const {return first_free - element;}
	size_t capacity() const {return cap - element;}
	void resize(size_t new_size);
	void reserve(size_t min_capacity);

	string *begin() const {return element;}
	string *end() const {return first_free;}


private:
	void initialize_alloc_n_copy(const string *b, const string *e);
	pair<string *, string *> alloc_n_copy(const string *b, const string *e);
	void chk_n_alloc();
	void reallocate_capacity();
	void reallocate_size();
	void reallocate(size_t n);
	void free();

	//why does it need to be static?
	static allocator<string> alloc;
	string * element;
	string * first_free;
	string * cap;
};
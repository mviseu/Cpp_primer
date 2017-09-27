#pragma once
#include <memory>
#include <string>
#include <vector>

using std::shared_ptr;
using std::weak_ptr;
using std::string;
using std::vector;
using std::size_t;

class ConstStrBlob;

class ConstStrBlobPtr {
public:
	ConstStrBlobPtr() {};
	ConstStrBlobPtr(const ConstStrBlob &sptr, size_t i);
	const string &deref() const;
	const string &operator*() const;
	const string *operator->() const;

	ConstStrBlobPtr &incr();

private:
	shared_ptr<const vector<string>> check(size_t i, const string &mess) const;
	const string &do_deref() const;
	weak_ptr<const vector<string>> wkpr;
	size_t curr = 0;
};
#pragma once
#include <memory>
#include <string>
#include <vector>
#include "14_16_StrVec.h"

using std::shared_ptr;
using std::weak_ptr;
using std::string;
using std::vector;
using std::size_t;

class StrBlob;

class StrBlobPtr {
	friend bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend int operator-(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
public:
	StrBlobPtr() {};
	StrBlobPtr(StrBlob &sptr, size_t i);
  	StrBlobPtr &operator+=(int i);
  	StrBlobPtr &operator-=(int i);
	StrBlobPtr &operator++();
	StrBlobPtr &operator--();
	StrBlobPtr operator++(int);
	StrBlobPtr operator--(int);
	const char &operator[](std::size_t i) const;
	char &operator[](std::size_t i);
	string &deref() const;
	StrBlobPtr &incr();

private:
	shared_ptr<vector<string>> check(size_t i, const string &mess) const;
	char &do_subscript(std::size_t i) const;
	weak_ptr<vector<string>> wkpr;
	size_t curr = 0;
};

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
StrBlobPtr operator+(const StrBlobPtr &lhs, int i);
StrBlobPtr operator-(const StrBlobPtr &lhs, int i);
int operator-(const StrBlobPtr &lhs, const StrBlobPtr &rhs);

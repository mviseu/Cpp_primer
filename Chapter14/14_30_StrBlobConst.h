#pragma once
#include <initializer_list>
#include <memory>
#include <string>
#include <vector>

using std::string;
using std::shared_ptr;
using std::weak_ptr;
using std::vector;
using std::initializer_list;
using std::make_shared;

class ConstStrBlobPtr;

class ConstStrBlob {
  friend class ConstStrBlobPtr;
  
public:
  using size_type = vector<string>::size_type;
  
  ConstStrBlob();
  ConstStrBlob(const initializer_list<string> &il);

  size_type size() const;
  bool empty() const;

  const string &front() const;
  const string &back() const;

  ConstStrBlobPtr begin() const;
  ConstStrBlobPtr end() const;

private:
  shared_ptr<const vector<string>> data;
  void check(size_type i, const string &message) const;
};
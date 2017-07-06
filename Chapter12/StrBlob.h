#pragma once
#include <initializer_list>
#include <memory>
#include <string>
#include <vector>

using std::string;
using std::shared_ptr;
using std::vector;
using std::initializer_list;
using std::make_shared;

class StrBlob {
public:
  using size_type = vector<string>::size_type;

  StrBlob();
  StrBlob(const initializer_list<string> &il);

  size_type size() const;
  bool empty() const;

  const string &front() const;
  const string &back() const;

  string &front();
  string &back();

  void push_back(const string &s);
  void pop_back();

private:
  shared_ptr<vector<string>> data;
  string &do_front() const;
  string &do_back() const;
  void check(size_type i, const string &message) const;
};
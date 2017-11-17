#include "16_12_Blob.h"
#include "16_12_BlobPtr.h"

#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::initializer_list;
using std::make_shared;
using std::out_of_range
;
Blob::Blob()
    : data(make_shared<vector<string>>()) {}
Blob::Blob(const initializer_list<string> &il)
    : data(make_shared<vector<string>>(il)) {}

const string &Blob::operator[](std::size_t i) const {
  return (*data)[i];  
}

string &Blob::operator[](std::size_t i) {
  return (*data)[i];
}

Blob::size_type Blob::size() const { return data->size(); }
bool Blob::empty() const { return data->empty(); }

void Blob::push_back(const string &s) { data->push_back(s); }

const string &Blob::front() const { return do_front(); }

string &Blob::front() { return do_front(); }

const string &Blob::back() const { return do_back(); }

string &Blob::back() { return do_back(); }

string &Blob::do_front() const {
  check(0, "front not valid on empty Blob");
  return const_cast<string &>(data->front());
}

string &Blob::do_back() const {
  check(0, "back not valid on empty Blob");
  return const_cast<string &>(data->back());
}

void Blob::pop_back() {
  check(0, "pop back not valid on empty Blob");
  data->pop_back();
}

void Blob::check(size_type i, const string &message) const {
  if (i >= data->size()) {
    throw out_of_range(message);
  }
}

BlobPtr Blob::begin() {return BlobPtr(*this, 0);}
BlobPtr Blob::end() {return BlobPtr(*this, data -> size());}

vector<string> *Blob::get() const {
  return data.get();
}

bool operator==(const Blob &lhs, const Blob &rhs) {
  return *lhs.data == *rhs.data;
}

bool operator!=(const Blob &lhs, const Blob &rhs) {
  return !(lhs == rhs);
}

bool operator<(const Blob &lhs, const Blob &rhs) {
  return std::lexicographical_compare((*lhs.data).begin(), (*lhs.data).end(), (*rhs.data).begin(), (*rhs.data).end());
}

bool operator>(const Blob &lhs, const Blob &rhs) {
  return rhs < lhs;
}

bool operator<=(const Blob &lhs, const Blob &rhs) {
  return !(rhs < lhs);
}

bool operator>=(const Blob &lhs, const Blob &rhs) {
  return !(lhs < rhs);
}

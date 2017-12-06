#include "16_30_StrBlob.h"
#include "16_28_SharedPtr.h"
#include "DebugDelete.h"
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::initializer_list;
using std::make_shared;
using std::out_of_range;

StrBlob::StrBlob()
    : data(SharedPtr<vector<string>>(new vector<string>(), DebugDelete())) {}
StrBlob::StrBlob(const initializer_list<string> &il)
    : data(SharedPtr<vector<string>>(new vector<string>({il}), DebugDelete())) {}
StrBlob::size_type StrBlob::size() const { return data->size(); }
bool StrBlob::empty() const { return data->empty(); }

void StrBlob::push_back(const string &s) { data->push_back(s); }

const string &StrBlob::front() const { return do_front(); }

string &StrBlob::front() { return do_front(); }

const string &StrBlob::back() const { return do_back(); }

string &StrBlob::back() { return do_back(); }

string &StrBlob::do_front() const {
  check(0, "front not valid on empty StrBlob");
  return const_cast<string &>(data->front());
}

string &StrBlob::do_back() const {
  check(0, "back not valid on empty StrBlob");
  return const_cast<string &>(data->back());
}

void StrBlob::pop_back() {
  check(0, "pop back not valid on empty StrBlob");
  data->pop_back();
}

void StrBlob::check(size_type i, const string &message) const {
  if (i >= data->size()) {
    throw out_of_range(message);
  }
}

vector<string> *StrBlob::get() const {
  return data.get();
}

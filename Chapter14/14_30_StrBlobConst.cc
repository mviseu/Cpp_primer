#include "14_30_StrBlobPtrConst.h"
#include "14_30_StrBlobConst.h"

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
ConstStrBlob::ConstStrBlob()
    : data(make_shared<vector<string>>()) {}
ConstStrBlob::ConstStrBlob(const initializer_list<string> &il)
    : data(make_shared<const vector<string>>(il)) {}
ConstStrBlob::size_type ConstStrBlob::size() const { return data->size(); }
bool ConstStrBlob::empty() const { return data->empty(); }

const string &ConstStrBlob::front() const {
  check(0, "front not valid on empty StrBlob");
  return data->front();
}

const string &ConstStrBlob::back() const {
  check(0, "back not valid on empty StrBlob");
  return data->back();  
}

void ConstStrBlob::check(size_type i, const string &message) const {
  if (i >= data->size()) {
    throw out_of_range(message);
  }
}

ConstStrBlobPtr ConstStrBlob::begin() const {return ConstStrBlobPtr(*this, 0);}
ConstStrBlobPtr ConstStrBlob::end() const {return ConstStrBlobPtr(*this, data -> size());}
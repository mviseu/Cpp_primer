#pragma once
#include "16_28_SharedPtr.h"
#include <initializer_list>
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>

using std::string;
using std::weak_ptr;
using std::vector;
using std::initializer_list;

template <typename T> class Blob;
template <typename T> bool operator==(const Blob<T> &lhs, const Blob<T> &rhs);
template <typename T> bool operator<(const Blob<T> &lhs, const Blob<T> &rhs);

template <typename T> class Blob {
  friend bool operator==<T>(const Blob &lhs, const Blob &rhs);
  friend bool operator< <T>(const Blob &lhs, const Blob &rhs); //space!

public:
  using size_type = typename vector<T>::size_type;
  
  Blob() {data = SharedPtr<std::vector<T>>(new std::vector<T>());}
  Blob(const initializer_list<T> &il) { data = SharedPtr<std::vector<T>>(new vector<T>(il)); }
  template <typename It> Blob(It beg, It end) { data = SharedPtr<std::vector<T>>(new vector<T>(beg, end)); }


  const T &operator[](std::size_t i) const {return (*data)[i];} 

  T &operator[](std::size_t i)  {return (*data)[i];}

  size_type size() const {return data->size();}
  bool empty() const {return data->empty();}



  const T &front() const {return do_front();}
  const T &back() const {return do_back();}

  T &front() {return do_front();} 
  T &back() {return do_back();}

  void push_back(const T &e) {data->push_back(e);}
  void pop_back() {
    check(0, "pop back not valid on empty Blob");
    data->pop_back();
  }

  vector<T> *get() const {
    return data.get();
  }

private:
  SharedPtr<vector<T>> data;
  T &do_front() const {
    check(0, "front not valid on empty Blob");
    return const_cast<T &>(data->front());
  }
  T &do_back() const {
    check(0, "back not valid on empty Blob");
    return const_cast<T &>(data->back());
  }
  void check(size_type i, const string &message) const {
    if (i >= data->size()) {
      throw std::out_of_range(message);
    }
  }
};

template <typename T> bool operator==(const Blob<T> &lhs, const Blob<T> &rhs) {return *lhs.data == *rhs.data;}
template <typename T> bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs) {return !(lhs == rhs);}
template <typename T> bool operator<(const Blob<T> &lhs, const Blob<T> &rhs) {return std::lexicographical_compare((*lhs.data).begin(), (*lhs.data).end(), (*rhs.data).begin(), (*rhs.data).end());}
template <typename T> bool operator>(const Blob<T> &lhs, const Blob<T> &rhs) {return rhs < lhs;}
template <typename T> bool operator<=(const Blob<T> &lhs, const Blob<T> &rhs) {return !(rhs < lhs);}
template <typename T> bool operator>=(const Blob<T> &lhs, const Blob<T> &rhs) {return !(lhs < rhs);}

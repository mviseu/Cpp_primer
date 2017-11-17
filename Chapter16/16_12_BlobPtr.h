#pragma once
#include <memory>
#include <string>
#include <vector>

using std::shared_ptr;
using std::weak_ptr;
using std::string;
using std::vector;
using std::size_t;

template <typename T> class BlobPtr;
template <typename T> bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
template <typename T> bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
template <typename T> int operator-(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
template <typename T> class Blob; 

template <typename T> class BlobPtr {
	friend bool operator==<T>(const BlobPtr &lhs, const BlobPtr &rhs);
	friend bool operator<<T>(const BlobPtr &lhs, const BlobPtr &rhs);
	friend int operator-<T>(const BlobPtr &lhs, const BlobPtr &rhs);
public:
	using value_type = typename T::value_type;
	BlobPtr() {};
	BlobPtr(Blob<T> &sptr, size_t i) : wkpr(sptr.data), curr(i) {}

  	BlobPtr &operator+=(int i)  {
		curr += i;
		auto curr_lower = curr - 1;
		i > 0 ? check(curr_lower, "Iterator arithmetic past the off-the-end") : check(curr, "Iterator arithmetic before start");
		return *this;
	}
  	BlobPtr &operator-=(int i) {
		return *this += -i;
  	}

	BlobPtr &operator++() {
		check(curr, "incremented past end");
		++curr;
		return *this;
	}
	BlobPtr &operator--()  {
		--curr;
		check(curr, "decremented past begin");
		return *this;
	}
	BlobPtr operator++(int)  {
		auto ret = *this;
		++*this;
		return ret;
	}
	BlobPtr operator--(int)  {
		auto ret = *this;
		--*this;
		return ret;
	}
	const value_type &operator[](std::size_t i) const  {return do_subscript(i);}
	value_type &operator[](std::size_t i) {return do_subscript(i);}
	T &deref() const {	
		auto sptr = check(curr, "Dereference past end");
		return (*sptr)[curr];
	}
	BlobPtr &incr() {	
		check(curr, "Incremented past end");
		++curr;
		return *this;
	}

private:
	shared_ptr<vector<T>> check(size_t i, const string &mess) const {
		auto sptr = wkpr.lock();
		if(!sptr) {
			throw runtime_error("Unbound BlobPtr");
		}
		if(i >= sptr -> size()) {
			throw out_of_range(mess);
		}
		return sptr;
	}
	value_type &do_subscript(std::size_t i) const  {
		auto sptr = check(curr, "Dereference past end");
		return const_cast<value_type &>((*sptr)[curr][i]);
	}
	weak_ptr<vector<T>> wkpr;
	size_t curr = 0;
};


template <typename T> bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	//meaning equality = same underlying string
	auto lhs_ptr = lhs.check(lhs.curr, "Dereference past end");
	auto rhs_ptr = rhs.check(rhs.curr, "Dereference past end");
	return (*lhs_ptr)[lhs.curr] == (*rhs_ptr)[rhs.curr];
}

template <typename T> bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	return !(rhs == lhs);
}

template <typename T> bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	//meaning equality = same underlying string
	auto lhs_ptr = lhs.check(lhs.curr, "Dereference past end");
	auto rhs_ptr = rhs.check(rhs.curr, "Dereference past end");
	return (*lhs_ptr)[lhs.curr] < (*rhs_ptr)[rhs.curr];
}

template <typename T> bool operator>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	return rhs < lhs;
}

template <typename T> bool operator>=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	return !(lhs < rhs);
}

template <typename T> bool operator<=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	return !(rhs < lhs);
}

template <typename T> BlobPtr<T> operator+(const BlobPtr<T> &lhs, int i) {
	BlobPtr<T> ret = lhs;
	return ret += i;
}

template <typename T> BlobPtr<T> operator-(const BlobPtr<T> &lhs, int i) {
	BlobPtr<T> ret = lhs;
	return ret += -i;
}

template <typename T> int operator-(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	return lhs.curr - rhs.curr;
}

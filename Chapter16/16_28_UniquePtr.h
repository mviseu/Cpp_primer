#pragma once
#include <iostream>
#include <memory>
#include <functional>
#include <stdexcept>



template <typename T, typename D> class UniquePtr;
template <typename T, typename D> void swap(UniquePtr<T, D> &lhs, UniquePtr<T, D> &rhs);


template <typename T, typename D = std::function<void(T*)> > class UniquePtr {

public:
	friend void swap<T, D>(UniquePtr &lhs, UniquePtr &rhs);
	// constructor
	UniquePtr(T *bptr = nullptr, const D &del = [](T*p){delete p;}) : ptr(bptr), deleter(del) {}
	UniquePtr(const D &del) : deleter(del) {}
	UniquePtr(const UniquePtr &sptr) = delete;
	UniquePtr(UniquePtr &&sptr) noexcept : ptr(sptr.ptr), deleter(std::move(sptr.deleter)) {sptr.ptr = nullptr;}
	// assignment
	UniquePtr &operator=(const UniquePtr &rhs) = delete;

	UniquePtr &operator=(UniquePtr &&rhs) noexcept {
		if(&rhs != this) {
			decrement_andif_destroy();
			ptr = rhs.ptr;
			deleter = std::move(rhs.deleter);
			rhs.ptr = nullptr;
		}
		return *this;
	}

	// destructor
	~UniquePtr() {
		decrement_andif_destroy();
	}
	//see if deleter is maintained post release
	T* release() {auto ptr_copy = ptr; ptr = nullptr; return ptr_copy;}
	void reset(T *rhs_ptr = nullptr);
	T &operator*() const;
	T *operator->() const;
	explicit operator bool() const;
	T *get() const {return ptr;}
	const D &get_deleter() const {return deleter;}
	void swap(UniquePtr &rhs);


private:
	T *ptr = nullptr;
	D deleter =  [](T*p){delete p;};


	void check_if_null() const;
	void decrement_andif_destroy() {
		if(ptr) {deleter(ptr);}
	}
};

template <typename T, typename D> T &UniquePtr<T, D>::operator*() const {
	check_if_null();
	return *ptr;	
}

template <typename T, typename D> T *UniquePtr<T, D>::operator->() const {
	return & this -> operator*();
}

template <typename T, typename D> void UniquePtr<T, D>::check_if_null() const {
	if(!ptr) {
		throw std::runtime_error("Attempt to dereference a null pointer");
	}
}

template <typename T, typename D> UniquePtr<T, D>::operator bool() const {
	return ptr;
}


template <typename T, typename D> void swap(UniquePtr<T, D> &lhs, UniquePtr<T, D> &rhs) {
	using std::swap;
	swap(lhs.ptr, rhs.ptr);
	swap(lhs.deleter, rhs.deleter);
}


template <typename T, typename D> void UniquePtr<T, D>::swap(UniquePtr &rhs) {
	using std::swap;
	::swap(*this, rhs);
}

template <typename T, typename D> void UniquePtr<T, D>::reset(T *bptr) {
	decrement_andif_destroy();
	ptr = bptr;
}

/*
Release
- Release sets the ptr to null and keeps the deleter
*/


/*
On Reset
- For Unique Ptr reset also keeps the old deleter if nothing else is specified (it is part of the type)
- Shared Ptr does not keep the old deleter upon reset
*/


/*
Shared Ptr - construct and assign

	move-assign moves the deleter
	copy-assign does not copy the deleter
	Same with copy/move constructors

*/

/*
TODO
- swap in clang - does it work?
*/

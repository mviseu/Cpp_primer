#pragma once
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
			deleter = rhs.deleter;
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
	void reset(T *rhs_ptr = nullptr, const D &rhs_deleter =  [](T*p){delete p;});
	T &operator*() const;
	T *operator->() const;
	explicit operator bool() const;
	T *get() const {return ptr;}
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


template <typename T, typename D> void UniquePtr<T, D>::reset(T *bptr, const D &del) {
	decrement_andif_destroy();
	ptr = bptr;
	deleter = del;
}

/*
TODO
- see if deleter is maintained post-release
- Does reset accept deleter?
- why does debugdelete swap not work:
- review
*/
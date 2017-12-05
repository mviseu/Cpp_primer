#pragma once
#include <memory>
#include <functional>
#include <stdexcept>



template <typename T> class SharedPtr;
template <typename T> void swap(SharedPtr<T> &lhs, SharedPtr<T> &rhs);

//how to use as private?
template <typename T> void set_ptrs_to_null(SharedPtr<T> &sptr) {
	sptr.ptr = nullptr;
	sptr.count = nullptr;
	sptr.deleter = nullptr;
} 

template <typename T> class SharedPtr {

public:
	friend void swap<T>(SharedPtr &lhs, SharedPtr &rhs);
	friend void set_ptrs_to_null<T>(SharedPtr &sptr);
	// constructor
	SharedPtr() = default;
	SharedPtr(T *bptr, const std::function<void(T*)> &del = nullptr) : ptr(bptr), deleter(del) {
		count = (bptr ? new int(1) : nullptr);
	}
	SharedPtr(const SharedPtr &sptr) : ptr(sptr.ptr), count(sptr.count) {++*count;}
	SharedPtr(SharedPtr &&sptr) noexcept : ptr(sptr.ptr), count(sptr.count), deleter(std::move(sptr.deleter)) {
		set_ptrs_to_null(sptr);
	}
	// assignment
	SharedPtr &operator=(const SharedPtr &rhs) {
		if(rhs.ptr) {
			++*rhs.count;
		}
		decrement_andif_destroy();
		copy_ptr_and_count(rhs);
		return *this;
	}

	SharedPtr &operator=(SharedPtr &&rhs) noexcept {
		if(&rhs != this) {
			decrement_andif_destroy();
			copy_ptr_and_count(rhs);
			deleter = std::move(rhs.deleter);
			set_ptrs_to_null(rhs);
		}
		return *this;
	}

	// destructor
	~SharedPtr() {
		reset();
	}
	void reset(T *rhs_ptr = nullptr, const std::function<void(T*)> &rhs_deleter = nullptr);
	T &operator*() const;
	T *operator->() const;
	explicit operator bool() const;
	T *get() const {return ptr;}
	int use_count() const;
	bool unique() const;
	void swap(SharedPtr &rhs);


private:
	T *ptr = nullptr;
	int *count = nullptr;
	std::function<void(T*)> deleter = nullptr;
	void check_if_null() const;
	void decrement_andif_destroy() {
		if(ptr && !--*count) {
			delete count;
			deleter ? deleter(ptr) : delete ptr;
		}
	}
	void copy_ptr_and_count(const SharedPtr &rhs) {
		ptr = rhs.ptr;
		count = rhs.count;
	}
};

template <typename T> T &SharedPtr<T>::operator*() const {
	check_if_null();
	return *ptr;	
}

template <typename T> T *SharedPtr<T>::operator->() const {
	return & this -> operator*();
}

template <typename T> void SharedPtr<T>::check_if_null() const {
	if(!ptr) {
		throw std::runtime_error("Attempt to dereference a null pointer");
	}
}

template <typename T> SharedPtr<T>::operator bool() const {
	return ptr;
}

template <typename T> int SharedPtr<T>::use_count() const {
	return (ptr ? *count : 0);
}

template <typename T> bool SharedPtr<T>::unique() const {
	return use_count() == 1;
}

template <typename T> void SharedPtr<T>::swap(SharedPtr &rhs) {
	using std::swap;
	swap(rhs.ptr, ptr);
	swap(rhs.count, count);
	swap(rhs.deleter, deleter);	
}

template <typename T> void swap(SharedPtr<T> &lhs, SharedPtr<T> &rhs) {
	using std::swap;
	lhs.swap(rhs);
}

template <typename T> void SharedPtr<T>::reset(T *bptr, const std::function<void(T*)> &del) {
	decrement_andif_destroy();
	ptr = bptr;
	count = (bptr ? new int(1) : nullptr);
	deleter = del;
}
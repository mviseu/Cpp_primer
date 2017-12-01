#pragma once
#include <memory>

template <typename T> class SharedPtr {
public:
	// constructor
	SharedPtr() = default;
	SharedPtr(T *bptr) : ptr(bptr), count(new int(1)) {}
	SharedPtr(const SharedPtr &sptr) : ptr(sptr.ptr), count(sptr.count) {++*count;}
	SharedPtr(SharedPtr &&sptr) noexcept : ptr(std::move(sptr.ptr)), count(std::move(sptr.count)) {
		sptr.ptr = nullptr;
		sptr.count = nullptr;
	}
	// assignment
	SharedPtr &operator=(const SharedPtr &rhs) {
		++*rhs.count;
		if(!--*count) {
			delete ptr;
			delete count;
		}
		ptr = rhs.ptr;
		count = rhs.count;
		return *this;
	}

	SharedPtr &operator=(SharedPtr &&rhs) noexcept {
		if(&rhs != this) {
			if(!--*count) {
				delete ptr;
				delete count;
			}
			ptr = std::move(rhs.ptr);
			count = std::move(rhs.count);
			rhs.ptr = nullptr;
			rhs.count = nullptr;
		}
		return *this;
	}
	// destructor
	~SharedPtr() {
		if(ptr && !--*count) {
			delete ptr;
			delete count;
		}
	}

private:
	T *ptr = nullptr;
	int *count = nullptr;
	//think of how to implement the deleter later
};
#pragma once
#include <string>
#include <memory>
#include <utility>
#include <initializer_list>
#include <algorithm>

using std::allocator;
using std::string;
using std::pair;
using std::initializer_list;

template <typename T> class Vec {
public:
	Vec() : element(nullptr), first_free(nullptr), cap(nullptr) {}
	Vec(const Vec &);
	Vec(Vec &&) noexcept;
	Vec(initializer_list<T> il);

	Vec &operator=(const Vec &);
	Vec &operator=(Vec &&rhs) noexcept;
	Vec &operator=(std::initializer_list<T> il);
	const T &operator[](std::size_t i) const;
	T &operator[](std::size_t i);
	~Vec();
	void push_back(const T &s);
	template <typename ... Args> void emplace_back(Args && ... args);

	size_t size() const {return first_free - element;}
	size_t capacity() const {return cap - element;}
	void resize(size_t new_size);
	void reserve(size_t min_capacity);

	T *begin() const {return element;}
	T *end() const {return first_free;}


private:
	void initialize_alloc_n_copy(const T *b, const T *e);
	pair<T *, T *> alloc_n_copy(const T *b, const T *e);
	void chk_n_alloc();
	void reallocate_capacity();
	void reallocate_size();
	void reallocate(size_t n);
	void free();

	static allocator<T> alloc;
	T * element;
	T * first_free;
	T * cap;
};

template <typename T> allocator<T> Vec<T>::alloc;

template <typename T> Vec<T>::Vec(initializer_list<T> il) {
	initialize_alloc_n_copy(il.begin(), il.end());
}

template <typename T> Vec<T>::Vec(const Vec &v) {
	initialize_alloc_n_copy(v.begin(), v.end());
}

template <typename T> Vec<T>::Vec(Vec &&v) noexcept :
	element(v.element), first_free(v.first_free), cap(v.cap) {
	v.element = v.first_free = v.cap = nullptr;
}

template <typename T> Vec<T> &Vec<T>::operator=(const Vec &rhs) {
	auto ret = alloc_n_copy(rhs.element, rhs.first_free);
	free();
	element = ret.first;
	first_free = cap = ret.second;
	return *this;
}

template <typename T> Vec<T> &Vec<T>::operator=(Vec &&rhs) noexcept{
	if(this != &rhs) {
		free();
		element = rhs.element;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.element = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

template <typename T> Vec<T> &Vec<T>::operator=(std::initializer_list<T> il) {
	auto ret = alloc_n_copy(il.begin(), il.end());
	free();
	element = ret.first;
	first_free = cap = ret.second;
	return *this;
}

template <typename T> const T &Vec<T>::operator[](std::size_t i) const {
	return element[i];
}

template <typename T> T &Vec<T>::operator[](std::size_t i) {
	return element[i];
}

template <typename T> Vec<T>::~Vec() {
	free();
}

template <typename T> void Vec<T>::resize(size_t new_size) {
	while(first_free > element + new_size) {
		alloc.destroy(--first_free);
	}
	while(first_free < element + new_size) {
		push_back(T());
	}
}

template <typename T> void Vec<T>::reserve(size_t min_capacity) {
	while(cap < element + min_capacity) {
		reallocate_capacity();
	}
}

template <typename T> void Vec<T>::push_back(const T &s) {
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

template <typename T>
template <typename ... Args> void Vec<T>::emplace_back(Args && ... args) {
	chk_n_alloc();
	alloc.construct(first_free++, std::forward<Args>(args) ...);
}

template <typename T> pair<T *, T *>Vec<T>::alloc_n_copy(const T *b, const T *e) {
	auto ret = alloc.allocate(e - b);
	return {ret, uninitialized_copy(b, e, ret)};
}

template <typename T> void Vec<T>::initialize_alloc_n_copy(const T *b, const T *e) {
	auto ret = alloc_n_copy(b, e);
	element = ret.first;
	first_free = cap = ret.second;
}

template <typename T> void Vec<T>::chk_n_alloc() {
	if(size() == capacity()) {
		reallocate_size();
	}
}

template <typename T> void Vec<T>::free() {
	if(element) {
		std::for_each(element, first_free, [](const T &s){alloc.destroy(&s);});
		alloc.deallocate(element, cap - element);
	}
}

template <typename T> void Vec<T>::reallocate_size() {
	reallocate(size());
}

template <typename T> void Vec<T>::reallocate_capacity() {
	reallocate(capacity());
}

template <typename T> void Vec<T>::reallocate(size_t n) {
	auto new_capacity = (n ? n * 2 : 1) ;
	auto ret = alloc.allocate(new_capacity);
	auto elem = element;
	auto dest = ret;
	for(size_t i = 0; i != size(); ++i) {
		alloc.construct(dest++, std::move(*elem++));
	}
	free();
	element = ret;
	first_free = dest;
	cap = element + new_capacity;
}


template <typename T> bool operator==(const Vec<T> &lhs, const Vec<T> &rhs) {
	return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <typename T> bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs) {
	return !(lhs == rhs);
}

template <typename T> bool operator<(const Vec<T> &lhs, const Vec<T> &rhs) {
	return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <typename T> bool operator>(const Vec<T> &lhs, const Vec<T> &rhs) {
	return rhs < lhs;
}

template <typename T> bool operator<=(const Vec<T> &lhs, const Vec<T> &rhs) {
	return !(rhs < lhs);
}

template <typename T> bool operator>=(const Vec<T> &lhs, const Vec<T> &rhs) {
	return !(lhs < rhs);
}
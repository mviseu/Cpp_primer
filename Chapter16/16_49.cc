#include <iterator>
#include <iostream>
#include <string>

std::ostream_iterator<std::string> out(std::cout, "\n");

template <typename T> void f(T) {
	out = "void f(T)"; 
}

template <typename T> void f(const T *) {
	out = "void f(const T *)";
}

template <typename T> void g(T) {
	out = "void g(T)";
}

template <typename T> void g(T *) {
	out = "void g(T *)";
}

int main() {
	int i = 42, *p = &i;
	const int ci = 0, *p2 = &ci;
	// only 1 viable candidate where argument deduction succeeds void g(T) with T deduced int
	g(42);

	// both g templates are viable and exact matches however g(T *) is more specialized so will be called
	g(p);

	// only 1 viable candidate g(T)
	g(ci);

	// both g templates are viable and exact matches hoewver g(T *) is more specialized so it is called
	g(p2);

	// only f(T) is viable
	f(42);

	// f(const T *) requires a conversion to const while f(T) is exact match so f(T) is called
	f(p);

	// only f(T) is viable
	f(ci);

	// both templates are exact matches but f(const T *) is more specialized so it will be called
	f(p2);
	return 0;
}
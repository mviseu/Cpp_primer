#include <iostream>
#include <string>
#include <vector>

template <typename T> std::ostream &print(std::ostream &os, const T &t) {
	return os << t;
}

template <typename T, typename ... Args> std::ostream &print(std::ostream &os, const T &t, const Args & ... rest) {
	os << t << ", ";
	return print(os, rest ...);
}

int main() {
	int i(1); double d(3.14); std::string s("hello"); const char arr[]("hi"); long l(42); std::vector<int> vec(5);
	print(std::cout, i, d, s, arr, l);
	std::cout << std::endl;
	print(std::cout, i);
	std::cout << std::endl;
	//won't compile - invalid since vector does not have overloaded << operator
	//print(std::cout, i, vec);
	return 0;
}


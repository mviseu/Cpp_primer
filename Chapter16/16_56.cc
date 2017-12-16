#include <string>
#include <sstream>
#include <iterator>
#include <iostream>


template <typename T> std::string debug_rep(const T &t);
template <typename T> std::string debug_rep(T *p);
std::string debug_rep(const std::string &s);
std::string debug_rep(const char *p);
std::string debug_rep(char *p);


template <typename T> std::string debug_rep(const T &t) {
	std::ostringstream ret;
	ret << t;
	return ret.str();	
}

template <typename T> std::string debug_rep(T *p) {
	std::ostringstream ret;
	ret << "pointer: " << p;
	if(p) {
		ret << " " << debug_rep(*p);
	} else {
		ret << "null ptr";
	}
	return ret.str();
}

std::string debug_rep(const std::string &s) {
	return '"' + s + '"'; 
}

std::string debug_rep(const char *p) {
	return debug_rep(std::string(p));
}

std::string debug_rep(char *p) {
	return debug_rep(std::string(p));
}

template <typename T> std::ostream &print(std::ostream &os, const T &t) {
	return os << t;
}

template <typename T, typename ... Args> std::ostream &print(std::ostream &os, const T &t, const Args & ... rest) {
	os << t << ", ";
	return print(os, rest ...);
}

// more clear that errorMsg requires at least 1 argument that is printed
template <typename T, typename ... Args> std::ostream &errorMsg(std::ostream &os, const T &t, const Args & ...rest) {
	return print(os, t, debug_rep(rest) ...);
}

int main() {
	errorMsg(std::cout, "error message");
	std::cout << std::endl;
	errorMsg(std::cout , "more than 1 error message", 1);
	return 0;
}
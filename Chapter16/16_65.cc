#include <string>
#include <sstream>
#include <iterator>
#include <iostream>


template <typename T> std::string debug_rep(const T &t);
template <typename T> std::string debug_rep(T *p);
std::string debug_rep(const std::string &s);
template <> std::string debug_rep(const char * t);
template <> std::string debug_rep(char * t);


template <typename T> std::string debug_rep(const T &t) {
	std::cout << "debug_rep(const T &t)" << std::endl;
	std::ostringstream ret;
	ret << t;
	return ret.str();	
}

template <typename T> std::string debug_rep(T *p) {
	std::cout << "debug_rep(T *p)" << std::endl;
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
	std::cout << "debug_rep(const std::string &s)" << std::endl;
	return '"' + s + '"'; 
}

// template specialization instead of overloading
template <> std::string debug_rep(const char * t) {
	std::cout << "Specialization of const char *" << std::endl;
	return debug_rep(std::string(t));	
}

template <> std::string debug_rep(char * t) {
	std::cout << "Specialization of char *" << std::endl;
	return debug_rep(std::string(t));	
}

int main() {
	std::ostream_iterator<std::string> out(std::cout, "\n");
	std::string s("Hello");
	out = debug_rep(s);
	const std::string s_const("Hello");
	out = debug_rep(s_const);

	std::string *p_s = &s;
	out = debug_rep(p_s);

	const std::string *p_csts = &s_const;
	out = debug_rep(p_csts);


	out = debug_rep("hi world");
	char arr[] = "Hello";

	out = debug_rep(arr);
	return 0;
}
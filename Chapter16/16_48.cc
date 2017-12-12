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
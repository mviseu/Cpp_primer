#include "19_2_StrVec.h"
#include <iostream>
#include <iterator>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::ostream_iterator;

int main() {
	StrVec vec_str, vec_str2(vec_str);
	vec_str.push_back("hello");
	vec_str.resize(3);
	cout << vec_str.size() << " " << vec_str.capacity() << endl;
	vec_str.reserve(1);
	cout << vec_str.size() << " " << vec_str.capacity() << endl;	
	cout << "cap: " << vec_str.capacity() << endl;
	cout << "size: " << vec_str.size() << endl;
	ostream_iterator<string> out(cout, " ");
	std::copy(vec_str.begin(), vec_str.end(), out);
	StrVec il({"This", "is", "a", "string"});
	std::copy(il.begin(), il.end(), out);
	
	vec_str.push_back("bye");
	cout << endl;
	cout << "cap: " << vec_str.capacity() << endl;
	cout << "size: " << vec_str.size() << endl;
	std::copy(vec_str.begin(), vec_str.end(), out);
	vec_str.push_back("bye again");
	cout << endl;
	cout << "cap: " << vec_str.capacity() << endl;
	cout << "size: " << vec_str.size() << endl;
	std::copy(vec_str.begin(), vec_str.end(), out);
	cout << endl;
	auto vec_copy(vec_str);
	std::copy(vec_copy.begin(), vec_copy.end(), out);
	cout << endl;
	vec_str2 = vec_copy;
	std::copy(vec_copy.begin(), vec_copy.end(), out);

	return 0;
}
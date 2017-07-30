#include "String.h"
#include "StrVec.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::vector;

int main() {
	/*
	String s,s2 =s;
	cout << s.size() << " " << s.capacity();
	s2.push_back('s');
	s2.push_back('t');
	s2.push_back('r');
	s2.push_back('i');
	s2.push_back('n');
	s2.push_back('g');
	ostream_iterator<char> out(cout);
	std::copy(s2.begin(), s2.end(), out);
	s = s2;
	std::copy(s.begin(), s.end(), out);*/
	//vector<String> vec = {}
	/*vector<String> vec;
	vec.push_back("String1");
	vec.push_back("String2");
	vec.push_back("String3");
	vec.push_back("String4");
	vec.front() = "String1Move";*/

	vector<StrVec> vec;
	vec.push_back({"String1"});
	vec.push_back({"String2"});
	vec.push_back({"String3"});
	vec.push_back({"String4"});
	vec.front() = {"String1Move", "String2Move"};
	return 0;
}
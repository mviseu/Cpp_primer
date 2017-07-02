#include <map>
#include <list>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>

using std::map;
using std::list;
using std::string;
using std::cout;
using std::endl;

void print(const map<string, list<size_t>> &word_lines) {
	for(const auto &elem : word_lines) {
		cout  << elem.first << " ";
		for(const auto &line : elem.second) {
			cout << line << " ";
		}
		cout << endl;
	}
}

int main() {
	map<string, list<size_t>> word_lines = {{"an", {1, 10, 21}},
										 {"hi", {12}},
										 {"the", {1, 2, 3}}	
										};
	print(word_lines);
	return 0;
}
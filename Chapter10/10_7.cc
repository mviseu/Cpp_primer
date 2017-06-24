#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <iterator>

using std::vector;
using std::list;
using std::cin;
using std::cout;
using std::endl;
using std::back_inserter;

int main() {
	vector<int> vec;
	list<int> lst;
	int i;
	while(cin >> i) {
		lst.push_back(i);
	}
	//has to ensure vec has a size to fit lst.end - lst.begin
	//simplest solution is to use back_inserter
	//another option would be to resize vec first and then copu
	copy(lst.begin(), lst.end(), back_inserter(vec));
	for(const auto &e : vec) {
		cout << e << endl;
	}

	vector<int> vec2;
	//use resize to change number of elements, reserve only to specify capacity
	//fill_n(vec2.begin(), 10, 0) is now not needed since resize uses value initialization
	vec2.resize(10);
	for(const auto &e : vec2) {
		cout << e << endl;
	}
	return 0;
}
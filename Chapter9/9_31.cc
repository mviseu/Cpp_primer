#include <forward_list>
#include <iostream>

using std::forward_list;
using std::cout;
using std::endl;

int main() {
	forward_list<int> fl = {0, 2, 4, 5, 9, 7, 55, 6, 9};
	//erase even -valued elements and duplicate odd elements
	//iterator arithmetic does not work for list/forward-list
	auto curr = fl.begin(), prev = fl.before_begin();
	while(curr != fl.end()) {
		if(*curr % 2) {
			prev = fl.insert_after(curr, *curr);
			++++curr;
		} else {
			curr = fl.erase_after(prev);
		}
	}
	for(const auto &e : fl) {
		cout << e << " " ;
	}
	cout << endl;

	return 0;
}
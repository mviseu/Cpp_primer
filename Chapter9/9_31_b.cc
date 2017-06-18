#include <list>
#include <iostream>

using std::list;
using std::cout;
using std::endl;

int main() {
	list<int> l = {0, 2, 4, 5, 9, 7, 55, 6, 9};
	//erase even -valued elements and duplicate odd elements
	//iterator arithmetic does not work for list/forward-list
	auto curr = l.begin();
	while(curr != l.end()) {
		if(*curr % 2) {
			curr = l.insert(curr, *curr);
			++++curr;
		} else {
			curr = l.erase(curr);
		}
	}
	for(const auto &e : l) {
		cout << e << " " ;
	}
	cout << endl;

	return 0;
}
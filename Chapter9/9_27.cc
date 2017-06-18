#include <forward_list>
#include <iostream>

using std::forward_list;
using std::cout;
using std::endl;

int main() {

	forward_list<int> flist = {0, 1, 7, 4, 6, 10, 99};

	auto prev = flist.cbefore_begin();
	auto curr = flist.cbegin();

	while(curr != flist.cend()) {
		if(*curr % 2) {
			curr = flist.erase_after(prev);
		} else {
			prev = curr++;
		}
	}
	for(const auto &e : flist) {
		cout << e << " ";
	}
	cout << endl;

	return 0;
}
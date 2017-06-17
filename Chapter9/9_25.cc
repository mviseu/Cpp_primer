#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;


int main() {
	list<int> li = {0, 1};
	//if both iterators are equal (including if they are both off-the-end) no elements are deleted
	//li.erase(li.cbegin(), li.cbegin());
	li.erase(li.cend(), li.cend());

	for(const auto &e : li) {
		cout << e << " ";
	}
	cout << endl;

	return 0;
}

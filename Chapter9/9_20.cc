#include <list>
#include <deque>
#include <iostream>

using std::cout;
using std::endl;
using std::list;
using std::deque;


int main() {
	list<int> lint = {2, 33, 7, 9, 8, 100, 42};
	deque<int> even;
	deque<int> odd;

	for(const auto &num : lint) {
		(num % 2 == 0 ? even : odd).push_back(num);
	}

	for(const auto &num : even) {
		cout << num << " ";
	}
	cout << endl;

	for(const auto &num : odd) {
		cout << num << " ";
	}
	cout << endl;
	return 0;
}
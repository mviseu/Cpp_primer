#include <vector>
#include <list>
#include <iostream>

using std::vector;
using std::list;
using std::cout;
using std::endl;

int main() {
	list<int> l = {0, 1, 2};
	vector<double> vDoub(l.cbegin(), l.cend());
	vector<int> vInt(l.cbegin(), l.cend());

	for(const auto &e : vDoub) {
		cout << e << " " ;
	}
	cout << endl;
	for(const auto &e : vInt) {
		cout << e << " " ;
	}
	cout << endl;
	return 0;
}
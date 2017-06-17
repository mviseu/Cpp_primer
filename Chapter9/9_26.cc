#include <vector>
#include <list>
#include <iostream>
#include <iterator>

using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::begin;
using std::end;

int main() {
	int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
	vector<int> iv(begin(ia), end(ia));
	list<int> il(begin(ia), end(ia));

	//for vector ideal is to use pop_back but they require erase
	auto viter = iv.cend();
	if(iv.size() > 0) {
		while(viter != iv.cbegin()) {
			viter = (*(viter - 1) % 2 ? --viter : iv.erase(viter - 1));
		}

	}

	//for list we can remove from the front
	auto liter = il.cbegin();
	if(il.size() > 0) {
		while(liter != il.cend()) {
			liter = (*liter % 2 ? il.erase(liter): ++liter);
		}

	}

	for(const auto &e : iv) {
		cout << e << " ";
	}
	cout << endl;

	for(const auto &e : il) {
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
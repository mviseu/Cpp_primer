#include <iostream>
using std::cout;
using std::endl;


int main() {
	constexpr size_t array_size = 10;
	int ia[array_size];

	//corrected ix to start at 0 instead of 1
	//replaced <= with <
	for(size_t ix = 0; ix < array_size; ++ix) {
		ia[ix] = ix ;
		cout << ix << " " ;
	}
	cout << endl;

	for(const auto &c : ia) {
		cout << c << " " ;
	}

	return 0;
}
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main() {
	constexpr int some_value = 3; 
	vector<int> iv = {2, 3, 4, 3, 6};

	vector<int>::iterator mid = iv.begin() + iv.size() / 2;
	//while loop needs scope
	//iter < mid to only check elements before the middle
	for(auto iter = iv.begin(); iter < mid; ++iter) {
		if(*iter == some_value) {
			//push_front not valid for vector
			++(iter = iv.insert(iter, 2 * some_value));
			//mid becomes invalid after insert. Redefine.
			mid = iv.begin() + iv.size() / 2;
		} 
	}

	for(const auto &e : iv) {
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
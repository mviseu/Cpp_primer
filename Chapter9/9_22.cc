#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main() {
	constexpr int some_value = 3; 
	vector<int> iv = {2, 2, 3, 2};
	vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
	//while loop needs scope
	//iter < mid to only check elements before the middle
	//insert is not efficienct for vector -> use list intead (later)
	while(iter < mid) {
		if(*iter == some_value) {
			//push_front not valid for vector
			iter = iv.insert(iter, 2 * some_value) + 2;
			//mid becomes invalid after insert. Redefine.
			mid = iv.begin() + iv.size() / 2;
		} else {
		//iter needs to be changed if some_value is not found
			++iter;
		}
	}

	for(const auto &e : iv) {
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
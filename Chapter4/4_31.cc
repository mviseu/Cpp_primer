#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
	vector<int> ivec(10);
	vector<int>::size_type cnt = ivec.size();

	//we can use postfix version in the same way since we are not using returned postfix rvalue
	//however it is more efficient to use prefix since it only evaluates operand once
	for(vector<int>::size_type ix = 0; ix != ivec.size(); 
		++ix, --cnt) {

		ivec[ix] = cnt;
	}


	for(const int &c : ivec) {
		cout << c << " ";
	}

	cout << endl;

	return 0;
}
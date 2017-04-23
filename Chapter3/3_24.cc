#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::begin;


int main() {

	vector<int> v1;
	int i = 0;

	while(cin >> i) {
		v1.push_back(i);
	}


	if(v1.empty()) {
		return 0;
	}

	auto leftEnd = v1.begin();
	auto rightEnd = v1.end() - 1;

	while(leftEnd < rightEnd) {
		cout << *leftEnd + *rightEnd << " ";
		++leftEnd;
		--rightEnd;


	}

	if(leftEnd == rightEnd) {
		cout << *leftEnd;

	}

	cout << endl;

	return 0;
}




#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;


int main() {
	//empty vectors v1 and v2
	vector<int>v1, v2;
	int a = 0, b = 0;
	auto size = v1.size();

	cout << "Please provide the size of vectors 1 and 2" << endl;
	cin >> size;

	cout << "Please provide the first vector" << endl;
	for(int i = 0; i != size && cin >> a; ++i) {
		v1.push_back(a);
	}


	cout << "Please provide the second vector" << endl;
	for(int i = 0; i != size && cin >> b; ++i) {
		v2.push_back(b);
	}

	for (const auto &c : v1)
		cout << c << " ";

	cout << endl;

	for (const auto &c : v2)
		cout << c << " ";

	cout << endl;


	if(v1 == v2) {
		cout << "The vectors are identical"<< endl;
	} else {
		cout << "The vectors are NOT identical" << endl;
	}


	return 0;
}
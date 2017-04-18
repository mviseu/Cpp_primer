#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
	int i;
	vector<int> v;
	//Hold read ints in a vector
	while(cin >> i) {
		v.push_back(i);

	}

	decltype(v.size()) j  ;
	j = 0;

	//prints the sum of two adjacent int in v
	while(j < v.size()) {
		if(j + 1 == v.size()) {
			//In case there are odd number of elements last element is printed alone
			cout << v[j] << endl;
		} else {
			cout << v[j] + v[j+1] << endl;
		}
		j = j + 2;
	}


	decltype(v.size()) k  ;
	k = 0;

	//prints the sum of the first/last, second/second to last etc
	while(k < v.size() / 2) {
			cout << v[k] + v[v.size() - (k + 1)] << endl;
		k = k + 1;
	}

	//For odd number of elements print middle only
	unsigned test = (v.size() - 0.5) / 2 ;
	unsigned half = v.size() / 2 ;


	if(half == test) {
	//In case there are odd number of elements the middle element is printed alone
		cout << v[v.size()/2] << endl;
	}
	return 0;
}
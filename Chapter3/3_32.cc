#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {

	int array[10] = {};
	int copyArray[10] = {};

	size_t i = 0;

	//we cannot assign one array to another
	for(auto &c : array) {
		c = i;
		copyArray[i] = array[i];
		i = i + 1;
	}


	//same with vectors
	vector<int> v; //because they will all have different values I will not initialise (empty vector)
	for(decltype(v.size()) j=0; j < 10; ++j) {
		v.push_back(j);
	}
	auto vCopy(v);

	for(const auto &c : vCopy) {
		cout << c << " " ;
	}
	cout << endl;

	return 0;
}
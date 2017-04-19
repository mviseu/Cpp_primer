#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
	vector<unsigned> scores(11, 0);
	unsigned grade = 0;

	while(cin >> grade)
		if (grade <= 100) {
			auto it = scores.begin() + (grade/10) ;
			*it += 1 ;
		}

	for(auto it = scores.begin(); it != scores.end(); ++it) {
		if (it < scores.end() - 1) {
			cout << *it << " ";
		} else {
			cout << *it << endl;
		}
	}


	return 0;
}
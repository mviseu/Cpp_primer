#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
	string words;
	vector<string> v1;

	//Read all the words and push them into vector v1
	while(cin >> words) {
		v1.push_back(words) ;
	}

	//Uppercase for all characters
	for(auto &c : v1) {
		for(auto &i : c) {
			i = toupper(i) ;
		}
	}

	vector<string> v2;
	decltype(v1.size()) i;
	string words8;
	i = 0;

	//i will loop every 0, 8, 16...
	while(i < v1.size()) {
		words8 = {};
		auto j = i;
		i = 8 * (i + 1);

		//j will increment 1 at a time within i(old) and i(new) range
		while(j != v1.size() && j != i) {
			words8 += v1[j];

			//print spaces after words except if it is the last of the 8/very last
			if(j < v1.size() - 1 && j < i - 1) {
				words8 += " "; 
			} ++j;
		}

		v2.push_back(words8);
	}

	//using const string & since c won't be modified
	for(const auto &c : v2) {
		cout << c << endl;
	}

	return 0;
}

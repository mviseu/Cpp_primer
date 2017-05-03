#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
	vector<string> vec;
	string s;	
	while(cin >> s) {
		vec.push_back(s);
	}
	if (!vec.empty()) {
		auto iter = vec.cbegin();
		unsigned counter = 1, counterMax = 1;
		string mostRepeatedString = *(vec.cbegin());
		while(iter != vec.cend() - 1) {
			if (*iter == *(iter + 1)) {
				++counter;
			} else {
				if(counter >= counterMax) {
					counterMax = counter;
					mostRepeatedString = *iter;
				}
				counter = 1;
			}
			++iter;
		}
		if(counter >= counterMax) {
			counterMax = counter;
			mostRepeatedString = *iter;
		}
		if(counterMax == 1) {
			cout << "There are no repeated words!" << endl;
		} else {
			cout << "The maximum number of duplicates is " << counterMax 
				 << " for the word " << mostRepeatedString << endl;
		}
	} 
	return 0;
}
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

//default initialized to empty
string sa[10];

//default initialized to 0
int ia[10];


main() {
	//array of 10 empty strings
	string sa2[10];


	//array of 10 undefined ints
	int ia2[10];

	//vector of 10 ints with value 0
	vector<int> v(10);

	for(const auto &c : ::sa) //explicitly requests the global sa
		cout << c << endl;

	for(const auto &c : ::ia)
		cout << c << endl; 

	for(const auto &c : sa2)
		cout << c << endl;

	for(const auto &c : ia2)
		cout << c << endl;

	for(const auto &c : v)
		cout << c << endl;

	return 0;
}
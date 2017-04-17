#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
//v1 is an empty vector (default initialization)
vector<int> v1;

for(auto &c : v1) {
	cout << c << endl;
}

//v2 contains 10 integers with default value 0
vector<int> v2(10);

for(auto &c : v2) {
	cout << c << endl;
}

//v3 containts 10 ints with value 42
vector<int> v3(10, 42);

for(auto &c : v3) {
	cout << c << endl;
}

//curly brackets for list initialization. V4 contains 1 element of value 10
vector<int> v4{10};

for(auto &c : v4) {
	cout << c << endl;
}

//v5 contains two integers with values 10 and 42
vector<int> v5{10, 42};

for(auto &c : v5) {
	cout << c << endl;
}

//because 10 is not a string, there is element count initialization. 
//v6 contains 10 empty strings
vector<string> v6{10};
for(auto &c : v6) {
	cout << c << endl;
}

//because 10 is not a string there is element count initialization.
//v7 contains 10 object strings "hi".
vector<string> v7{10, "hi"};

for(auto &c : v7) {
	cout << c << endl;
}


return 0;
}
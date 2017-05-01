#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {

	//problem: missing initializer and incrementing iter
	string s = "Hello";
	
	//the iter variable was not initialized before being used
	//Possible solution (example):

	string::iterator iter = s.begin();
	while(iter != s.end()) {
		cout << *iter;
		iter += 1;
	} 


	cout << endl; 
	return 0;
}
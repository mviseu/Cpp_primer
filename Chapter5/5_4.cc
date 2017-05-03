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

	//status must be defined outside while block if it going to be used outside while blocl
	/*
	bool status;
	while(status = find(word)) {
	}

	if(!status) 
		;
	*/

	cout << endl; 
	return 0;
}
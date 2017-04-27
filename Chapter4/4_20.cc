#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {
	vector<string> vec ={"I", "like", "C++"};
	vector<string>::iterator iter = vec.begin();

	/*
	post fix increments iter but returns rvalue of old iter
	we are dereferencing still the first element
	cout << *iter++ << endl;
	cout << *iter << endl;
	*/

	/*Cannot increment a string type

	(*iter)++

	*/

	/* .operator has precedence 
		empty() is not member of iter

	*iter.empty();
	*/

	/*This is valid since it dereferences first to get string
	 empty is member of string

	cout << iter->empty() << endl;
	*/

	/*Not possible to prefix increment a type string
	++*iter */

	//sees if first string is empty
	//iter is then incremented

	// (*(iter++)).empty();

	cout << iter++ -> empty() << endl ;

	return 0;
}
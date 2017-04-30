#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
	int x = 2, y = 1, a = 2, b = 1;


	//sizeof has precedence over sum
	//size of int = 4 plus y=1 -> 5
	cout << "Parenthesis: " << ((sizeof x) + y) << endl;
	cout << "Default: " << sizeof x + y << endl;

	//size of int = 4 < 1 is false > prints 0
	cout << "Parenthesis: " << ((sizeof a) < b) << endl;
	cout << "Default: " << (sizeof a < b) << endl;

	//(*p).mem[i]
	// sizeof (p -> mem[i]) 
	// sizeof (f())
	return 0;
}
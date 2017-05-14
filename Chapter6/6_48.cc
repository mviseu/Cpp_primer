#include <iostream>
#include <cassert>
#include <string>

using std::string;
using std::cin;

int main() { 

string sought = "hi";
string s;

while(cin >> s && s != sought) {

}

//cin is implicitly converted to bool true if last read was successful. To false if last read was a failure.
//this checks if sought was found without reaching invalid input first.
assert(cin);

return 0;

}
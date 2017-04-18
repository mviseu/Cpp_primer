#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
//ivec is empty
vector<int> ivec;
// we should not add elements using subscripting
//careful since it compiles
//ivec[0] = 42; 

//use push_back
ivec.push_back(42);

for(const auto &c : ivec)
	cout << c << endl;

return 0;
}
#include <vector>

using std::vector;

// function declaration
int f(int, int);

// pointer to function type
using falias = int(int, int);


int main() {
	vector<falias*> vec;
	return 0;
}

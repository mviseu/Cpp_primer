#include "X.h"
#include <vector>

X f(X x) {
	return x;
}

using std::vector;
int main() {
	X x1;
	//f(x1);
	//X x2 = x1;
	//X x3 = x1;
	//x2 = x1;
	//X * p1 = new X(x1);
	//delete p1;
	 vector<X> vec;
	 vec.reserve(2);
	 cout << "1: " << endl;
	 vec.push_back(x1);
	 cout << "2: " << endl;
	 vec.push_back(x1);
	 cout << "3: " << endl;
	//vec.push_back(x1);
	return 0;
}
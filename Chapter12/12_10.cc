#include <memory>
#include <iostream>

using std::shared_ptr;
using std::cin;
using std::cout;
using std::endl;


void process(shared_ptr<int> ptr, shared_ptr<int> &p) {
	cout << p.use_count() << endl;
	cout << ptr.use_count() << endl;
	if(ptr.unique()) {
		cout << ++*ptr << endl;
	}
}

int main() {
	shared_ptr<int> p(new int(3));
	//this is legal. p will share with process argument ptr since it is initialized based on p.
	process(shared_ptr<int>(p),p);
	cout << p.use_count() << endl;
	return 0;
}
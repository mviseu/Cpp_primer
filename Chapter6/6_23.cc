#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::begin;
using std::end;

void print (const int *p) {
	if(p)
		cout << *p << endl;
}

void print(const char *pc) {
	if(pc) {
		while(*pc) {
			cout << *pc++ ;
		}
		cout << endl;
	}
}

void print(const int *beg, const int *end) {
	while(beg != end) {
		cout << *beg++ << " ";
	}
	cout << endl;

}

void print(const int ia[], const size_t size) {
	for(size_t ctr = 0; ctr < size; ++ctr) {
		cout << ia[ctr] << " ";
	}
	cout << endl;
}


void print(const int (&arrayRef)[2]) {
	for(const int &c : arrayRef) {
		cout << c << " ";
	}
	cout << endl;
}


int main() {
	int i = 0, j[2] = {0,1};

	print(&i);

	print("Hello!");

	print(begin(j), end(j));

	print(begin(j), end(j) - begin(j));

	print(j);



	return 0;
}
#include "14_8.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {
	Book NonDel("Title", 30, 6.3), b2 = NonDel, b3;
	cout << NonDel << endl;
	Book SpecTitle("Title");
	Book SpecTitlePages("Title", 30);
	Book Default;
	Book BIn1;
	Book BIn2;
	cin >> BIn1;
	cout << BIn1;
	cin >> BIn1;
	cout << BIn2;
	if(b2 == NonDel) {
		cout << "b2 is equal to NonDel" << endl;
	}
	if(b2 != b3) {
		cout << "b2 is different from b3" << endl;
	}
	return 0;
}
#include "14_8.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {
	Book NonDel("Title", 30, 6.3);
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
	return 0;
}
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <deque>

using std::deque;
using std::vector;
using std::back_inserter;
using std::front_inserter;
using std::inserter;
using std::cout;
using std::endl;
using std::for_each;

int main() {
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << "original sequence: ";
	for_each(v.cbegin(), v.cend(), [](int i) {cout << i << " ";});
	cout << endl;

	//front_inserter 
	deque<int> dfront;
	copy(v.cbegin(), v.cend(), front_inserter(dfront));
	cout << "front inserter: "; //the sequence will be reversed
	for_each(dfront.cbegin(), dfront.cend(), [](int i) {cout << i << " ";});
	cout << endl;

	//back_inserter 
	vector<int> vback;
	copy(v.cbegin(), v.cend(), back_inserter(vback));
	cout << "back inserter: "; //sequence will be the same
	for_each(vback.cbegin(), vback.cend(), [](int i) {cout << i << " ";});
	cout << endl;


	//inserter
	vector<int> vinsert;
	copy(v.cbegin(), v.cend(), inserter(vinsert, vinsert.begin()));
	cout << "inserter: "; //sequence will be the same
	for_each(vinsert.cbegin(), vinsert.cend(), [](int i) {cout << i << " ";});
	cout << endl;

	return 0;
}
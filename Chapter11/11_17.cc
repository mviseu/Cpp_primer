#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>

using std::string;
using std::vector;
using std::multiset;
using std::inserter;
using std::cout;
using std::back_inserter;
using std::endl;

int main() {
	vector<string> v = {"foo", "bar", "42"};
	multiset<string> c = {"hello", "world"};
	//inserts the values of v into c -> however these are ordered anyway
	copy(v.begin(), v.end(), inserter(c, c.end()));

	std::ostream_iterator<string> out(cout, " ");
	copy(c.cbegin(), c.cend(), out);
	cout << endl;
	//error: no member named push_back in multiset (ordered by < operator)
	//copy(v.begin(), v.end(), back_inserter(c));

	//pushes the elements of multiset into vector - > equivalent to push_back
	copy(c.begin(), c.end(), inserter(v, v.end()));
	copy(v.cbegin(), v.cend(), out);

	cout << endl;
	copy(c.begin(), c.end(), back_inserter(v));
	copy(v.cbegin(), v.cend(), out);
	return 0;
}
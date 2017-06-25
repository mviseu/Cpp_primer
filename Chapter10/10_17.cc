//use Sales_data_10_12.cc file to compile together with this file
#include <vector>
#include <iostream>
#include "Sales_data_10_12.h"
#include <fstream>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

ostream &print(ostream &os, const vector<Sales_data> vec) {
	for(const auto &item : vec) {
		print(os, item);
	}
	return os;
}

int main() {
	ifstream input("infile");
	if(!input) {
		return -1;
	}
	vector<Sales_data> vec;
	//read into vector
	for(Sales_data item; read(input, item); vec.push_back(item));
	ofstream output("outfile");
	print(output, vec);
	sort(vec.begin(), vec.end(), [](const Sales_data &s1, const Sales_data &s2) {return s1.isbn() < s2.isbn();});
	print(output, vec);

	return 0;
}
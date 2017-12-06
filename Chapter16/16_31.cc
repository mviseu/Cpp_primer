#include "16_31_Blob.h"
#include <iostream>
#include <iterator>
#include <memory>

int main() {
	std::ostream_iterator<std::string> os(std::cout, "\n");

	Blob<std::string> v1({"Hello", "new", "world"}), v2 = {"new"}, v3 = v1;
	if(v1 == v3) {
		os =  "v1 and v3 are equal";
	}
	if(v2 != v1) {
		os = "v2 and v1 are different";
	}
	if(v1 < v2) {
		os = "v1 is less than v2";
	}
	if(v2 > v1) {
		os = "v2 is greater than v1";
	}
	if(v1 <= v3) {
		os = "v1 is less or equal to v3";
	}
	if(v2 >= v1) {
		os = "v2 is greater or equal to v1";
	}
	//16.24
	int arr[] = {0, 1, 2, 3};
	Blob<int> blob(std::begin(arr), std::end(arr));
	vector<long> vec({3, 4, 5});
	Blob<long> blob2(vec.begin(), vec.end());
	vector<string> vecStr = {"Hello", "new", "world"};
	Blob<string> blob3(vecStr.begin(), vecStr.end());
	return 0;
}

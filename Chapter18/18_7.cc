#include "18_7_Blob.h"
#include "18_7_BlobPtr.h"
#include <iostream>
#include <iterator>
#include <memory>

int main() {
	std::ostream_iterator<std::string> os(std::cout, "\n");

	Blob<std::string> v1({"Hello", "new", "world"}), v2 = {"new"}, v3 = v1;
	BlobPtr<std::string> p1(v1, 0), p2(v2, 0), p3(v1, 0);

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
	if(p1 == p3) {
		os = "p1 and p3 are equal";
	}
	if(p1 != p2) {
		os = "p1 and p2 are different";
	}
	if(p1 >= p3) {
		os = "p1 is greater or equal to p3";
	}
	if(p1 <= p3) {
		os = "p1 is less or equal to p3";
	}
	if(p1 < p2) {
		os = "p1 is less than p2";
	}
	if(p2 > p1) {
		os = "p2 is more than p1";
	}
	std::cout << p1[0] << p1[1] << p1[2] << p1[3] << std::endl;
	auto pnew = p1++;
	std::cout << pnew - p1 << std::endl;

	//16.24
	int arr[] = {0, 1, 2, 3};
	Blob<int> blob(std::begin(arr), std::end(arr));
	vector<long> vec({3, 4, 5});
	Blob<long> blob2(vec.begin(), vec.end());
	vector<string> vecStr = {"Hello", "new", "world"};
	Blob<string> blob3(vecStr.begin(), vecStr.end());

	// bad alloc exception in Blob constructor
	std::vector<int> a = {1, 2};
	Blob<int> blob_bad_alloc(a.cend(), a.cbegin());

	return 0;
}

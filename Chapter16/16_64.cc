#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

template <typename T> typename std::vector<T>::iterator::difference_type Count(const std::vector<T> &vec, const T &val) {
	//return std::count(vec.cbegin(), vec.cend(), val);
	std::cout << "Using original template" << std::endl;
	typename std::vector<T>::iterator::difference_type ret = 0;
	for(const auto &elem : vec) {
		if(val == elem) {
			++ret;
		}
	}
	return ret;
}

template <> std::vector<const char *>::iterator::difference_type Count(const std::vector<const char *> &vec, 
																		const char * const &val) {
	std::cout << "Using specialization" << std::endl;
	typename std::vector<const char *>::iterator::difference_type ret = 0;
	for(const auto &elem : vec) {
		if(0 == strcmp(elem, val)) {
			++ret;
		}
	}
	return ret;
}


int main() {

	std::vector<int> vecI({0, 42, 6, 7, 0});
	std::vector<double> vecD({3.14, 5, 3.14, 3.14});
	std::vector<std::string> vecS({"This", "is", "new", "word", "new"});

	std::cout << Count(vecI, 3) << std::endl;
	std::cout << Count(vecD, 3.14) << std::endl;
	std::cout << Count(vecS, std::string("new")) << std::endl;

	const char * oldPtr = "new";
	std::vector<const char *> vecPtr({"This", "is", oldPtr, "word", "new", "new"});
	const char * newPtr = "new";

	std::cout << Count(vecPtr, newPtr) << std::endl;

	return 0;
}
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>
//decltype type is an rvalue so it will return a copy of the element -> return type is the element type
//however:element must have an overloaded + (unnecessary burden)
template <typename It> 
auto fnc3(It beg, It end) -> decltype(*beg + 0) {
	return *beg;
}


template <typename It>
auto fnc4(It beg, It end) -> typename std::remove_reference<decltype(*beg)>::type {
	return *beg;
}


int main() {
	std::vector<std::string> vec = {"Hello", "new", "world"};
	// error since string cannot add + 0 
	//std::cout << fnc3(vec.begin(), vec.end()) << std::endl;
	std::cout << fnc4(vec.begin(), vec.end()) << std::endl;

	std::vector<int> vecInt(10);
	std::cout << fnc3(vecInt.begin(), vecInt.end()) << std::endl;
	std::cout << fnc4(vecInt.begin(), vecInt.end()) << std::endl;
	return 0;
}

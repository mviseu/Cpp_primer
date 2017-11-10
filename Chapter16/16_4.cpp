#include "16_4.h"
#include <list>
#include <vector>
#include <string>
#include <iostream>

int main() {
	std::vector<int> vec = {0, 1, 2, 3, 4, 5};
	std::list<std::string> ls = {"Hello", "this", "is", "a", "list", "of", "strings"};
	fd::find(vec.begin(), vec.end(), 6);
	std:: cout << (fd::find(vec.begin(), vec.end(), 6) == vec.end()) << std::endl;
	std::cout <<(fd::find(ls.begin(), ls.end(), "this") == ls.end()) << std::endl;
	return 0;
}

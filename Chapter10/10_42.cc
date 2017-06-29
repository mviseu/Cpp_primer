#include <list>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>

void elimDupl(std::list<std::string> &ls) {
	ls.sort();
	ls.unique();
}

int main() {
	std::list<std::string> ls = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	std::ostream_iterator<std::string> out(std::cout, " ");
	elimDupl(ls);
	std::for_each(ls.cbegin(), ls.cend(), [&](const std::string &s){out = s;});

	return 0;
}
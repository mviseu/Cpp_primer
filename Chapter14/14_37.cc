#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

class IsEqual {
public:
	IsEqual(int eval) : equal_value(eval) {}
	bool operator() (int val) const {
		return val == equal_value;
	}

private:
	int equal_value;


};

int main() {
	std::vector<int> vec = {0, 1, 3, 0, 5};
	std::replace_if(vec.begin(), vec.end(), IsEqual(0), 42);
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
	return 0;
}
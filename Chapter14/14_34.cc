#include <iostream>

struct IfThenElse {
	int operator() (int i1, int i2, int i3) const {
		return i1 ? i2 : i3;
	}
};

int main() {
	IfThenElse if_object;
	std::cout << if_object(0, 2, 3) << std::endl;
	std::cout << if_object(1, 2, 3) << std::endl;
	return 0;
}

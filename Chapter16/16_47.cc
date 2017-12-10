#include <utility>
#include <iostream>

template <typename F, typename T1, typename T2> void flip(F fnc, T1 &&t1, T2 &&t2) {
	fnc(std::forward<T2>(t2), std::forward<T1>(t1));
}

void fnc(int &&rVal, int &lVal) {
	std::cout << rVal << " " << ++lVal << std::endl;
}


int main() {
	int i = 1;
	flip(&fnc, i, 4);
	//i has changed since int &is preserved from flip to fnc
	//call to fnc inside flip is valid since std::forward preserves rvalue of t2
	std::cout << i << std::endl;
	return 0;
}
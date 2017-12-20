#include <bitset>
#include <iostream>

int main() {

	//2^5 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00100000
	std::cout << std::bitset<64>(32) << std::endl;
	//00000000 00001111 01101001 10110101
	std::cout << std::bitset<32>(1010101) << std::endl;
	return 0;
}
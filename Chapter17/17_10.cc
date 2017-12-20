#include <bitset>
#include <iostream>

std::bitset<32> getFibonacciFromString() {
	std::string fib = "1000000010000100101110";
	return std::bitset<32>(fib);
}

std::bitset<32> getFibonacciFromDefault() {
	std::bitset<32> bit;
	for(std::size_t ref_minus2 = 0, ref_minus1 = 1, ref = 1; ref < 22; ref_minus2 = ref_minus1,
																	   ref_minus1 = ref,
																	   ref = ref_minus2 + ref_minus1) {
		bit.set(ref);
	}
	return bit; 
}

int main() {
	std::cout << getFibonacciFromString() << std::endl;
	std::cout << getFibonacciFromDefault() << std::endl;
	return 0;
}
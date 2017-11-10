#pragma once
#include <iostream>

template <typename T, unsigned D> void print(T (&arr) [D]) {
	for(const auto &elem : arr) {
		std::cout << elem << std::endl;
	}
}

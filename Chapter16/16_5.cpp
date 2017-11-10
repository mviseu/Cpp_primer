#include "16_5.h"
#include <string>

int main() {
	constexpr int arr[5] = {0, 1, 2, 3, 4};
	print(arr);
	const std::string arr2[3] = {"Hello", "new", "world"};
	print(arr2);
	return 0;
}

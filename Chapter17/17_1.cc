#include <tuple>
#include <vector>
#include <string>
#include <utility>

int main() {
	auto tup = std::make_tuple(10, 20, 30);
	auto tup2 = std::make_tuple(std::string(), std::vector<std::string>(), std::pair<std::string, int>());
	return 0;
}
#include <vector>
#include <fstream>
#include <iostream>
#include <memory>

void exercise(int *b, int *e) {
	std::vector<int> v(b,e);
	//int *p = new int[v.size()];
	//solution 1
	//std::unique_ptr<int []> p(new int[v.size()]);
	//solution 2
	std::shared_ptr<int> p(new int[v.size()], [](int *p1) {delete [] p1;});
	std::ifstream in("ints");
}

int main() {
	std::vector<int> vec = {1, 2, 3};
	auto beg = &vec[0];
	auto end = &vec[2];
	exercise(beg, end);
	return 0;
}
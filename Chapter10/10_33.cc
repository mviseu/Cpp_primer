#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>

int main(int argc, char **argv) {
	if(argc != 4) {
		return -1;
	} 

	std::ifstream infile(argv[1]);
	std::istream_iterator<int> in_iter(infile), eof;
	std::ofstream odd(argv[2]), even(argv[3]);
	std::ostream_iterator<int> odd_iter(odd, " "), even_iter(even, "\n");

	for_each(in_iter, eof, [&](int i) {(i % 2 ? odd_iter : even_iter) = i;});

	return 0;
}
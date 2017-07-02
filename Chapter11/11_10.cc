#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using std::map;
using std::vector;
using std::list;
using std::back_inserter;


int main() {
	map<vector<int>::iterator, int> map_iter_vector_int;
	vector<int> vec = {0, 1, 2, 3};
	auto vec_begin = vec.begin();
	std::for_each(vec.cbegin(), vec.cend() - 1, [&](int i) {map_iter_vector_int[vec_begin + i] = i;});


	/*map<list<int>::iterator, int> map_iter_list_int;
	list<int> list = {0};
	auto list_begin = list.begin();
	//this does not work since there is now way to sort the keys according to the "less than" operator. List has bidirectional iterators which means it does not support
	//relational iterator operations such as iter1 < iter2, which means the keys cannot be ordered.
	map_iter_list_int[list_begin] = *list_begin;*/

	return 0;
}
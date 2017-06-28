#include "Sales_item.h"
#include <iterator>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>
#include <numeric>

int main() {
	std::ifstream book_sales("book_sales");
	std::istream_iterator<Sales_item> iter(book_sales), eof;
	std::vector<Sales_item> vec(iter, eof);
	std::sort(vec.begin(), vec.end(), [](const Sales_item &item1, const Sales_item &item2) {return item1.isbn() < item2.isbn();});

	for(auto start_iter = vec.cbegin(), end_iter = vec.cend(); start_iter != vec.cend(); start_iter = end_iter) {
		end_iter = std::find_if(start_iter, vec.cend(), [=](const Sales_item &item) {return item.isbn() != start_iter -> isbn();});
		std::cout << std::accumulate(start_iter + 1, end_iter, *start_iter) << std::endl;
	}

	return 0;
}
#include "17_4_Sales_data.h"
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <tuple>
#include <vector>

using matches = std::tuple<std::vector<Sales_data>::size_type, std::vector<Sales_data>::const_iterator,
															   std::vector<Sales_data>::const_iterator>;

std::vector<matches> findBook(const std::vector<std::vector<Sales_data>> &trans, const std::string &book) {
	std::vector<matches> res;
	for(auto store_it = trans.cbegin(); store_it != trans.cend(); ++store_it) {
		auto found = std::equal_range(store_it->cbegin(), store_it->cend(), book, compareIsbn);
		if(found.first != found.second) {
			res.push_back(std::make_tuple(store_it - trans.cbegin(), found.first, found.second));
		}
	}
	return res;
}


int main() {
	Sales_data S1("XX", 3, 2);
	Sales_data S2("XX", 2, 2);
	std::unordered_multiset<Sales_data> setSales({S1, S2, S1 + S2});

	std::copy(setSales.begin(), setSales.end(), std::ostream_iterator<Sales_data>(std::cout));
	return 0;
}
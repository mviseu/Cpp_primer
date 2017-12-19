#include "17_4_Sales_data.h"
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <tuple>
#include <vector>
#include <numeric>

//uses my own struct

struct Match {
Match(std::vector<Sales_data>::size_type in, std::vector<Sales_data>::const_iterator beg,
											 std::vector<Sales_data>::const_iterator en)
: index(in), begin(beg), end(en) {}

std::vector<Sales_data>::size_type index = 0;
std::vector<Sales_data>::const_iterator begin;
std::vector<Sales_data>::const_iterator end;

};

std::vector<Match> findBook(const std::vector<std::vector<Sales_data>> &trans, const std::string &book) {
	std::vector<Match> res;
	for(auto store_it = trans.cbegin(); store_it != trans.cend(); ++store_it) {
		auto found = std::equal_range(store_it->cbegin(), store_it->cend(), book, compareIsbn);
		if(found.first != found.second) {
			res.push_back(Match(store_it - trans.cbegin(), found.first, found.second));
		}
	}
	return res;
}

void reportResults(std::istream &is, std::ostream &os, const std::vector<std::vector<Sales_data>> &trans) {
	std::string s;
	while(is >> s) {
		auto find_book = findBook(trans, s);
		if(find_book.empty()) {
			os << "There are no transactions for book: " << s << std::endl;
			continue;
		}
		for(const auto &elem : find_book) {
			os << "For book " << s << ", the store with index " << elem.index 
			   << " has following transaction sum: \n" << std::accumulate(elem.begin, elem.end, Sales_data(s))
			   << std::endl; 
		}
	}
}

int main() {
	Sales_data S1("XX", 3, 2);
	Sales_data S2("XX", 2, 2);
	Sales_data S3("XY", 3, 2);
	Sales_data S4("XY", 2, 2);
	std::vector<Sales_data> store1 = {S1, S2, S3};
	std::vector<Sales_data> store2 = {S4};
	std::vector<std::vector<Sales_data>> all = {store1, store2};

	reportResults(std::cin, std::cout, all);
	return 0;
}
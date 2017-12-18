#include "Sales_data.h"
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <iterator>

int main() {
	Sales_data S1("XX", 3, 2);
	Sales_data S2("XX", 2, 2);
	std::unordered_multiset<Sales_data> setSales({S1, S2, S1 + S2});

	std::copy(setSales.begin(), setSales.end(), std::ostream_iterator<Sales_data>(std::cout));
	return 0;
}
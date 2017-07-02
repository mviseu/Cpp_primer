#include <set>
#include "Sales_data_11_11.h"
#include <string>

using std::string;
using std::multiset;

bool compareISBN(const Sales_data &item1, const Sales_data &item2) {
	return item1.isbn() < item2.isbn();
}

int main() {
	typedef bool (*compare_ptr) (const Sales_data &, const Sales_data &);

	multiset<Sales_data, compare_ptr> sales(compareISBN);

	using compare_ptr_using = bool (*)(const Sales_data &, const Sales_data &);

	multiset<Sales_data, compare_ptr_using> sales_using(compareISBN);

	multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)> sales_def(compareISBN);

	return 0;
}
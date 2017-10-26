#pragma once

#include "15_3_Quote.h"
#include <map>
#include <set>
#include <memory>
#include <iostream>

class Basquet {

public:
	void add_item(const Quote &item);
	void add_item(Quote &&item);

	double total_receipt(std::ostream &os) const;

private:
	static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) {
		return lhs->isbn() < rhs->isbn();
	}
	std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};
};
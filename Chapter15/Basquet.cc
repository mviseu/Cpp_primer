#include "Basquet.h"
#include <iostream>
#include <memory>
#include "15_3_Quote.h"


void Basquet::add_item(const Quote &item) {
	items.insert(std::shared_ptr<Quote>(item.clone()));
}

void Basquet::add_item(Quote &&item) {
	items.insert(std::shared_ptr<Quote>(std::move(item).clone()));
}



double Basquet::total_receipt(std::ostream &os) const {
	double sum = 0.0;
	for(auto item = items.cbegin(); item != items.cend(); item = items.upper_bound(*item)) {
		sum += print_total(os, **item, items.count(*item));
		os << std::endl;
	}
	os << "Total sale:" << sum << std::endl;
	return sum;
}

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
struct Sales_data
{
	std::string isbn() const {
		return bookNo;
	}
	Sales_data &combine(const Sales_data &rhs) {
		nr_units += rhs.nr_units;
		revenue += rhs.revenue;
		return *this;
	}
	std::string bookNo;
	unsigned nr_units = 0 ;
	double revenue = 0.0 ;
};

#endif

#pragma once
#include <string>

using std::string;

class Date {
public:
	Date(const string &date);
	unsigned getDay() const {
		return day;
	}
	unsigned getMonth() const {
		return month;
	}
	unsigned getYear() const {
		return year;
	}
private:
	unsigned day = 1;
	unsigned month = 1;
	unsigned year = 1990;	
};
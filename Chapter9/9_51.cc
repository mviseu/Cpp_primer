#include "9_51.h"
#include <iostream>

using std::cout;
using std::endl; 

namespace {
		unsigned convertStringMonth(const string &date) {
		if(date.find("Jan") != string::npos || date.find("January") != string::npos) {
			return 1;
		}
		if(date.find("Feb") != string::npos || date.find("February") != string::npos) {
			return 2;
		}
		if(date.find("Mar") != string::npos || date.find("March") != string::npos) {
			return 3;
		}
		if(date.find("Apr") != string::npos || date.find("April") != string::npos) {
			return 4;
		}
		if(date.find("May") != string::npos) {
			return 5;
		}
		if(date.find("Jun") != string::npos || date.find("June") != string::npos) {
			return 6;
		}
		if(date.find("Jul") != string::npos || date.find("July") != string::npos) {
			return 7;
		}
		if(date.find("Aug") != string::npos || date.find("August") != string::npos) {
			return 8;
		}
		if(date.find("Sep") != string::npos || date.find("September") != string::npos) {
			return 9;
		}
		if(date.find("Oct") != string::npos || date.find("October") != string::npos) {
			return 10;
		}
		if(date.find("Nov") != string::npos || date.find("November") != string::npos) {
			return 11;
		}
		if(date.find("Dec") != string::npos || date.find("December") != string::npos) {
			return 12;
		}
		return 0;
	}

	unsigned convertUnsignedMonth(const string &date) {
		const string separators = ", /";
		//stoi in the last number
		const auto i = date.find_first_of(separators);
		if(i != string::npos && i + 1 < date.size()) {
			return stoul(date.substr(i + 1));
		}
		return 0;
	}

	unsigned convertDay(const string &date) {
		const string numbers = "0123456789";
		//stoi in the first number
		const auto i = date.find_first_of(numbers);
		if(i != string::npos) {
			return stoul(date.substr(i));
		}
		return 0;
	}	

	unsigned convertYear(const string &date) {
		const string separators = ", /";
		//stoi in the last number
		const auto i = date.find_last_of(separators);
		if(i != string::npos && i + 1 < date.size()) {
			return stoul(date.substr(i + 1));
		}
		return 0;
	}
}



Date::Date(const string &date) {
	if(date.find_first_not_of("0123456789/ ,") != string::npos) {
		month = convertStringMonth(date);
	} else {
		month = convertUnsignedMonth(date);
	}
	day = convertDay(date);
	year = convertYear(date);
}

int main() {
	Date test("September 2, 1990");
	cout << "day: " << test.getDay() 
	<< " month: " << test.getMonth() 
	<< " year: "  << test.getYear() << endl;
	return 0;
}
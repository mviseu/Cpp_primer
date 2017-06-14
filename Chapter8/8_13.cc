#include "8_13.h"
#include <fstream>
#include <sstream>
#include <iostream>

using std::ifstream;
using std::istringstream;
using std::ostringstream;
using std::cout;
using std::endl;
using std::cerr;


bool isPhoneValid(const string &phone) {
	for(const auto &c : phone) {
		if(!isdigit(c)) {
			return false;
		}
	}
	return true;
}

string format(const string &phone) {
	string formatted;
	for(auto iter = phone.cbegin(); iter != phone.cend(); ++iter) {
		formatted += *iter;
		if(iter != phone.cend() - 1 && (iter - phone.cbegin()) % 3 == 2) {
			formatted += '-';
		}
	}
	return formatted;
}


int main() {

	ifstream input("infile");
	if(input.fail()) {
		cerr << "Provide infile" << endl;
		return -1;
	}

	vector<PersonInfo> people;
	string line, phone;

	istringstream record;	
	while(getline(input, line)) {
		PersonInfo person;
		record.str(line);
		record >> person.name;
		while(record >> phone) {
			person.phones.push_back(phone);
		}
		people.push_back(person);
		record.clear();
	}
	
	for(const auto &entry : people) {
		ostringstream formatted, badNumb;
		for(const auto &nums : entry.phones) {
			if(!isPhoneValid(nums)) {
				badNumb << " " << nums;
			} else {
				formatted << " " << format(nums);
			}
		}

		if(badNumb.str().empty()) {
			cout << entry.name << " " << formatted.str() << endl;
		} else {
			cerr << "Error. Name " << entry.name << " has invalid numbers" 
				 << badNumb.str() << endl;
		}
	}

	return 0;
}
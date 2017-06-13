#include "8_11.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using std::ifstream;
using std::istringstream;
using std::endl;
using std::cerr;
using std::cout;
using std::string;
using std::vector;


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

	//checking
	for(const auto &p : people) {
		cout << p.name << endl;
		for(const auto &ph : p.phones) {
			cout << ph << endl;
		}
	}

	return 0;
}
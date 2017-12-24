#include <fstream>
#include <sstream>
#include <iostream>
#include <regex>

using std::ifstream;
using std::istringstream;
using std::ostringstream;
using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::vector;

struct PersonInfo {
	string name;
	vector<std::smatch> phones;
};

bool isValid(const std::smatch &m) {
	if(m[1].matched) {
		return m[3].matched && (!m[4].matched || m[4].str() == " ");

	} else {
		return !m[3].matched && m[4].str() == m[6].str();

	}
}

string format(const std::smatch &m) {
	string formatted = m[2].str() + " " + m[5].str() + " " + m[7].str();
	return formatted;
}

int main() {

	ifstream input("infile_phone");
	if(input.fail()) {
		cerr << "Provide infile" << endl;
		return -1;
	}

	std::string phone_pattern = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	std::regex phone_regex(phone_pattern);

	vector<PersonInfo> people;
	string line, phone;

	istringstream record;	
	while(getline(input, line)) {
		PersonInfo person;
		record.str(line);
		record >> person.name;
		people.push_back(person);
		for(std::sregex_iterator it(line.cbegin(), line.cend(), phone_regex), it_end;
			it != it_end; ++it) {
			person.phones.push_back(*it);
		}
		record.clear();
	}
	for(const auto &entry : people) {
		ostringstream formatted, badNumb;
		for(const auto &nums : entry.phones) {
			if(isValid(nums)) {
				formatted << " " << format(nums);
			} else {
				badNumb << " " << nums.str();
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
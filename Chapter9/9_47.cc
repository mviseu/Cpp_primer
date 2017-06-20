#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

vector<string::size_type> findAlphabetic(const string &s) {
	const string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	vector<string::size_type> v;
	string::size_type pos = 0;
	while((pos = s.find_first_of(alphabet, pos)) != string::npos) {
		v.push_back(pos);
		++pos;
	}
	return v;
}

vector<string::size_type> findNumberic(const string &s) {
	const string numbers = "0123456789";
	vector<string::size_type> v;
	string::size_type pos = 0;
	while((pos = s.find_first_of(numbers, pos)) != string::npos) {
		v.push_back(pos);
		++pos;
	}
	return v;
}

vector<string::size_type> findNotAlphabetic(const string &s) {
	const string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	vector<string::size_type> v;
	string::size_type pos = 0;
	while((pos = s.find_first_not_of(alphabet, pos)) != string::npos) {
		v.push_back(pos);
		++pos;
	}
	return v;
}

vector<string::size_type> findNotNumeric(const string &s) {
	const string numbers = "0123456789";
	vector<string::size_type> v;
	string::size_type pos = 0;
	while((pos = s.find_first_not_of(numbers, pos)) != string::npos) {
		v.push_back(pos);
		++pos;
	}
	return v;
}



int main() {
	const string s = "ab2c3d7R4E6";
	vector<string::size_type> valpha = findAlphabetic(s), vnumber = findNumberic(s);
	for(const auto &e : valpha) {
		cout << "At position " << e << " there is alphabetic character "
			 << s[e] << endl;
	}

	for(const auto &e : vnumber) {
		cout << "At position " << e << " there is numeric character "
			 << s[e] << endl;
	}

	valpha = findNotNumeric(s), vnumber = findNotAlphabetic(s);

	for(const auto &e : valpha) {
		cout << "At position " << e << " there is alphabetic character "
			 << s[e] << endl;
	}

	for(const auto &e : vnumber) {
		cout << "At position " << e << " there is numeric character "
			 << s[e] << endl;
	}

	return 0;
}
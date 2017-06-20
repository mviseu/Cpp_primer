#include <vector>
#include <string>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;

int sumI(vector<string>&vs) {
	int sum = 0;
	for(const auto &s : vs) {
		sum += stoi(s);
	}
	return sum;
}

double sumD(vector<string>&vs) {
	double sum = 0;
	for(const auto &s : vs) {
		sum += stod(s);
	}
	return sum;
}

int main() {
	vector<string> vI = {"0", "1", "40", "3"};
	vector<string> vD = {".0", "3.0", "0.15"};
	cout << "sum int: " << sumI(vI) << endl;
	cout << "sum double: " << sumD(vD) << endl;
	return 0;
}
#include <map>
#include <string>
#include <iostream>

using std::map;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {

	map<string, int> m = {{"Month", 1}};
	auto m_iter = m.begin();
	m_iter -> second = 2;
	cout << m_iter -> first << " " << m_iter -> second << endl;
	return 0;
}
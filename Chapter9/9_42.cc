#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::endl;
using std::cout;

int main() {
	char c;
	string s;
	s.reserve(200);
	while(cin >> c) {
		cout << "size: " << s.size() << " capacity: " << s.capacity() << endl;
		s += c;
	}
	cout << s << endl;
	s.shrink_to_fit();
	cout << "size: " << s.size() << " capacity: " << s.capacity() << endl;
	return 0;
}
#include <map>
#include <string>
#include <iostream>

using std::multimap;
using std::string;
using std::cout;
using std::endl;

int main() {
	multimap<string, string> bookstore = {{"Jane Austen", "Pride and Prejudice"},
										   {"Shakespeare", "Romeo and Juliet"},
										   {"Shakespeare", "Hamlet"}
										 };

	string author = "Charles Dickens";
	string work = "Romeo and Juliet";
	auto ret = bookstore.find(author);
	for(auto cnt = bookstore.count(author); cnt; --cnt, ++ret) {
		//cout << cnt << endl;
		if(work == ret -> second) {
			bookstore.erase(ret);
			break;
		}
	}
	for(const auto &p : bookstore) {
		cout << p.first << " " << p.second << endl;
	}
	return 0;
}
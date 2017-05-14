#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

inline string makePlural(size_t ctr, const string &word, const string &ending = "s") {
  return ctr > 1 ? word + ending : word;
}

int main() { 

	cout << makePlural(2, "Success", "es") << endl;
	cout << makePlural(2, "Failure") << endl;
	cout << makePlural(2, "Failure") << endl;

	return 0; 

}

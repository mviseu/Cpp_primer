#include <iostream>
#include <string>


using std::cout;
using std::endl;
using std::string;

int main(int argc, char **argv) {
  string sTotal;
  for(auto row = 0; row < argc; ++row) {
  	string sRow(argv[row]);
	sTotal += sRow + " ";
  }

  cout << sTotal << endl;

  return 0;
}

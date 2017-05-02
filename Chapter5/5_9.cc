#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

	unsigned counterVowels = 0;
	char c;

	while(cin >> c) {
		if (c == 'a' || c == 'A')
			++counterVowels;
		else if (c == 'e' || c == 'E')
			++counterVowels;
			 else if (c == 'i' || c == 'I')
				++counterVowels;
				  else if (c == 'o' || c == 'O') 
					++counterVowels;
					   else if (c == 'u' || c == 'U') 
						++counterVowels;
	}

	cout << counterVowels << endl;

	return 0;
}
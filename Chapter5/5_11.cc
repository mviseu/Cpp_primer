#include <iostream>

using std::cin;
using std::noskipws;
using std::cout;
using std::endl;

int main() {

	char c;
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, 
			 blankSpaceCnt = 0, tabCnt = 0, newLineCnt = 0,
			 otherCnt = 0 ;

	while(cin >> noskipws >> c) {
		switch (c) {
			//No need to break after 'a' label since 'A' might also match
			case 'a':
			case 'A':
				++aCnt;
				break;
			case 'e':
			case 'E':
				++eCnt;
				break;
			case 'i':
			case 'I':
				++iCnt;
				break;
			case 'o':
			case 'O':
				++oCnt;
				break;
			case 'u':
			case 'U':
				++uCnt;
				break;
			case ' ':
				++blankSpaceCnt;
				break;
			case '\t':
				++tabCnt;
				break;
			case '\n':
				++newLineCnt;
				break;
			default:
				++otherCnt;
		}
	}

	cout << "a or A: " 		<< aCnt << '\n'
		 << "e or E: " 		<< eCnt << '\n'
		 << "i or I: " 		<< iCnt << '\n'
		 << "o or O: " 		<< oCnt << '\n'
		 << "u or U: " 		<< uCnt << '\n'
		 << "Blank space: " << blankSpaceCnt << '\n'
		 << "Tab: " 		<< tabCnt << '\n'
		 << "New line: " 	<< newLineCnt << '\n'
		 << "Other: " 		<< otherCnt << endl;

	return 0;
}
#include <iostream>
#include <string>

using std::cin;
using std::noskipws;
using std::cout;
using std::endl;
using std::string;

int main() {

	char c;
	string s;
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, 
			 blankSpaceCnt = 0, tabCnt = 0, newLineCnt = 0,
			 ffCnt = 0, flCnt = 0, fiCnt = 0,
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
			case 'f': {
				if(cin >> noskipws >> c) {
					switch (c) {
						case 'f':
							++ffCnt;
							break;
						case 'l':
							++flCnt;
							break;
						case 'i':
							//an fi sequence does not count for vowel i counter 
							++fiCnt;
							break;
						case 'a':
						case 'A':
							//f counts for otherCnt and a for ++a counter
							++otherCnt;
							++aCnt;
							break;
						case 'e':
						case 'E':
							++otherCnt;
							++eCnt;
							break;
						//lower case i has been considered
						case 'I':
							++otherCnt;
							++iCnt;
							break;
						case 'o':
						case 'O':
							++otherCnt;
							++oCnt;
							break;
						case 'u':
						case 'U':
							++otherCnt;
							++uCnt;
							break;
						case ' ':
							++otherCnt;
							++blankSpaceCnt;
							break;
						case '\t':
							++otherCnt;
							++tabCnt;
							break;
						case '\n':
							++otherCnt;
							++newLineCnt;
							break;
						default:
							otherCnt = otherCnt + 2;
					}
				} else {
					++otherCnt;
				}
				break;
			}
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
		 << "ff: " 			<< ffCnt << '\n'
		 << "fl: " 			<< flCnt << '\n'
		 << "fi: " 			<< fiCnt << '\n'
		 << "Other: " 		<< otherCnt << endl;

	return 0;
}
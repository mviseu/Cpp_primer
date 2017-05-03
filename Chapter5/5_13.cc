

int main() {

	//a) insert break after each case.
	// 'i', 'o', 'u' need to have own case labels since default may include other characters (not only i, o or u)
/*	unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
	char ch = next_text();

	switch (ch) {
		case 'a':
			++aCnt;
			break;
		case 'e':
			++eCnt;
			break;
		case 'i':
		case 'o':
		case 'u':
			++iouCnt;
			break;
		default:
			;
	} */


	/*
	unsigned evenCnt = 0, oddCnt = 0;

	int digit = get_num() % 10;

	//case 1, 3 replaced by case 1: case 3:
	//added negative remainder cases 
	switch (digit) {
		case -1: case -3: case -5: case -7: case -9:
		case 1: case 3: case 5: case 7: case 9:
			++oddCnt;
			break;

	//replace case 10 by case 0
		case -2: case -4: case -6: case -8:
		case 0: case 2: case 4: case 6: case 8:
			++evenCnt;
			break;
	} 
	*/

/*
	//get a >=0 value
	unsigned index = some_value();

	switch (index) {
		//Add a scope to initialize ix inside case 1 scope
		case 1: {
			int ix = get_value();
			//check if ix is in range
			if (ix >= 0 && ix < ivec.size())
				ivec[ix] = index;
			break;

		}
		default: {
			//Scope added to default case and ix is initialized again
			int ix = ivec.size() - 1;
			//check of ivec is not empty
				if(!ivec.empty()) 
					ivec[ix] = index;
		}
	}
*/

	/*
	//The case labels must be const or constexpr
	constexpr unsigned ival = 512, jval = 1024, kval = 4096;
	unsigned swt = get_bufCnt();
	//initialize bufsize in case it is not handled by the switch
	unsigned bufsize = 0;

	switch (swt) {

		//fall through to avoid duplicating the bufsize calculation		
		case ival:
		case jval:
		case kval:
			bufsize = swt * sizeof (int); 
			break;

		//added default
		default:
			;
	} */


	return 0;
}
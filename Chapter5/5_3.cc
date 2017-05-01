#include <iostream>


using std::endl;
using std::cout;

int main() {
	int val = 0, sum = 0;

/*	while(val <= 10) {
		sum += val;
		++val;
	}
*/

	//Alternative 1: comma operator inside loop with only 1 statement instead of block
	/*while(val <= 10) 
		sum += val, ++val; */
	
	//Alternative 2: comma operator in the control structure with null statement inside the loop
	//The comma operator returns the right hand operand
	while(val <= 10 && (sum += val, ++val)) {
		
	}

	return 0;
}
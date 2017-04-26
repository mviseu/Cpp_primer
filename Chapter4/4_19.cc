#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
	vector<int> vec{2,1,3};
	int *ptr = &vec[0];
	int ival = 0;

	/*
	The order of evaluation here is clear because we are dealing with logical && operator
	Checks the left hand FIRST
	Check if not null 
	if not null -> increment ptr return *(old ptr rvalue) */

	if(ptr != 0 && *ptr++ ) {
		cout << "ptr is not null" << endl;
	}
	
	/*This first increments ival and returns old ival rvalue
	if old ival is non zero the && continues
	new ival is evaluated and if non zero is true. if zero, is false. */

	if(ival++ && ival) {
		cout << "Both old ival and new ival are non zeroes" << endl;
	} 

	/*Order of evaluation is NOT clear 
	vec[ival++] <= vec[ival];
	will it evaluate ival++ first or ival first?
	If it evaluates ival++ first then this means:
	vec[ival] <= vec[ival + 1]
	Which makes sense.
	If it evaluates ival first then this means:
	vec[ival] <= vec[ival]
	Which will always be true if ival is within index range -> does not make sense
	 */

	return 0;
}
#include <iostream>
#include <typeinfo>

using std::cout;
using std::endl;

int main() {

	char cval;
	int ival = 1;
	unsigned int uival;
	float fval;
	double dval;


	//'a' promoted to int and summed to 3
	// assignment then converts result into char
	/*cval = 'a' + 3;
	cout << typeid(cval).name() << endl; */

	//ival converted to double
	//unsigned int uival converted to signed double to perform subtraction
	//assignment converts double into float
	/*fval = uival - ival * 1.0;

	cout << typeid(fval).name() << endl; */

	//float and unsigned int have 4 bytes-
	//unsigned int converted to float
	//assignment converts to double

	/*cout << typeid(uival * fval).name() << endl;	
	dval = uival * fval;
	cout << typeid(dval).name() << endl; */

	// ival + fval is converted to float
	// this result is converted to double to sum with dval
	// the assignment changes type to char
	cval = ival + fval + dval;	

	cout << typeid(ival + fval).name() << endl; 
	cout << typeid(ival + fval + dval).name() << endl; 
	cout << typeid(cval).name() << endl; 

	return 0;
}
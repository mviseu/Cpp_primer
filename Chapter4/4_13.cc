#include <iostream>
#include <typeinfo>

using std::cout;
using std::endl;

int main() {
	int i;
	double d;

	//Assignment is right associative so i = 3.5 is evaluated first
	//the returned value has the same type as the left hand operand
	// i is int so i = 3
	//d is double so d = 3.0 

	d = i = 3.5;

	cout << "i: " << i << endl;
	cout << "d: " << d << endl;
	cout << "type i: " << typeid(i).name() << endl;
	cout << "type d: " << typeid(d).name() << endl;

	int a;
	double b;

	//b is a double -> assigned 3.5
	//a is an int -> assigned 3
	a = b = 3.5;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "type a: " << typeid(a).name() << endl;
	cout << "type b: " << typeid(b).name() << endl;



	return 0;
}
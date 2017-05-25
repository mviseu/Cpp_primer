#include "7_49.h"
#include <string>

using std::string;


int main() {
	Sales_data i;
	string s;
	/* 1. declaration Sales_data &combine(const Sales_data &rhs)
	argument type conversion from string to const string to be used in constructor
	1st implicit class conversion from const string to sales_data -> creates a temp
	Sales_data temp implicitly converted into const sales_data to be used in combine
	const & can be binded to temps*/


	/* 2. declaration Sales_data &combine(Sales_data &rhs)
		implicit conversion from string to const string to be used in constructor
		1st implicit class conversion from const string to sales_data -> creates a temp
		temp cannot be used as combine argument since plain reference cannot be binded to a temp*/

	/*3. declaration Sales_data &combine(Sales_data rhs)
	     implicit conversion from string to const string to be used in argument of constructor
	     1st implicit class conversion to create Sales_data object -> creates a temp 
	     temp is copied into Sales_data creating a perfect match for combine*/

	/* 4. declaration Sales_data &combine(const Sales_data &rhs) const
	argument type conversion from string to const string to be used in constructor
	1st implicit class conversion from const string to sales_data -> creates a temp
	Sales_data temp implicitly converted into const sales_data to be used in combine
	const & can be binded to temps
	HOWEVER: not allowed since combine changes *this and therefore it cannot be const*/
	i.combine(Sales_data(s)); 
	return 0;
}
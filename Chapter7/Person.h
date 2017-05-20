#ifndef PERSON_H
#define PERSON_H
#include <string>

using std::string;
using std::istream;
using std::ostream;

struct Person
{
	//member functions
	const string & Name() const {return NameID; }
	const string & Address() const {return AddressID; }

	//data members
	string NameID;
	string AddressID;
};
	//nonmember interface functions
istream & read(istream &, Person &);
ostream & print(ostream &, Person &);
#endif
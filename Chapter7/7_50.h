#pragma once
#include <string>

using std::string;
using std::istream;
using std::ostream;

class Person {

friend istream & read(istream &, Person &);
friend ostream & print(ostream &, Person &);

public:
	//constructors
	Person() = default;
	Person(const Person &P) : 
	NameID(P.Name()), AddressID(P.Address()) {}
	//user specifies only the name or only the address
	Person(const int i, const string &S)
	{
		if(i == 1) 
			NameID = S;
		if(i == 2)
			AddressID = S;
	}

	//member functions
	const string & Name() const {return NameID; }
	const string & Address() const {return AddressID; }

private:
	//data members
	string NameID;
	string AddressID;
};
	//nonmember interface functions
istream & read(istream &, Person &);
ostream & print(ostream &, Person &);
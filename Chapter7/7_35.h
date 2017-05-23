#pragma once

#include <string>

using std::string;

//which definition of Type or initVal is used for each of these names?
//note: before corrections TypeS was named Type 

typedef string TypeS;
//return type is string
TypeS initVal();

class Exercise {

public:
	//First error: Type is already defined in the outer class scope (before this definition)	
	//solution: used different names (TypeS and Type)
	typedef double Type;
	//Return and parameter types are doubles (looks before/inside class scope first)
	Type setVal(Type);
	//Return type is double
	//needs to be defined so it can be used in Exercise::setVal
	Type initVal() {return 0;}

private:
	int val;
};

//return type Type is string if class scope is not used in return-> differs from return type in class declaration
//parameter type is double
//Uses initVal from inside class, not from outer scope
Exercise::Type Exercise::setVal(Type parm) {
	val = parm + initVal();
	return val;
}

/*Summary of overall solution
1) used different names for TypeS = string or Type = double;
2) Scope Exercise::Type return
3) initVal() needs to be defined to be used in Exercise::setVal */
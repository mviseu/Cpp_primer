#pragma once

#include <vector>

using std::vector;

class Example {
public:
	//a static data member cannot be defined inside class scope
	//this is why its definition was passed on to 7_58.cc
	static double rate;
	//static const member can have in-class initializers
	static const int vecSize = 20;
	//only static const/constexpr members can have in-class initializers
	//In-class initializers must be preceded by = or {}
	static vector<double> vec;

};
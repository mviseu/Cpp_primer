#pragma once
#include <string>

using std::string;

class Screen {

public:
	using pos = string::size_type;
	void dummy_fcn(pos height) {
		cursor = width * height;
	}

private:
	pos cursor = 0, height = 0, width = 0;

/*if pos is in last line of class
this is an error since pos is required for other class member declarations. 
pos must be aliased before it is used in other member declarations
public:
	using pos = string::size_type; */
};
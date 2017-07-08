#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

struct destination
{
	string s;
};
struct connection
{
	connection() : ptr(nullptr) {}
	destination * ptr;
};
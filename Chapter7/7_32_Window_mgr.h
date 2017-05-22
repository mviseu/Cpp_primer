#pragma once

#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::ostream;

class Screen;

class Window_mgr {
public:
	using ScreenIndex = vector<Screen>::size_type;
	void clear(ScreenIndex i);
	Window_mgr();

private:
	vector<Screen> Screens;
	
};

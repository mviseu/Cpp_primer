#pragma once

#include <iostream>
#include <string>
#include "7_32_Window_mgr.h"
using std::string;
using std::cout;
using std::ostream;


class Screen {

friend void Window_mgr::clear(ScreenIndex);

public:
  using pos = string::size_type;
  // constructors
  Screen() = default;
  Screen(pos h, pos w) : height(h), width(w), contents(h * w, ' ') {}
  Screen(pos h, pos w, char c) : height(h), width(w), contents(h * w, c) {}

  // member functions
  // implicitly inline
  char get() const { return contents[cursor]; }
  // defined outside the class body
  // get char at certain location
  char get(pos r, pos c) const;
  // move the cursor
  Screen &move(pos r, pos c);
  Screen &set(char c);
  Screen &set(pos r, pos col, char ch);
  Screen &display(ostream &os) {
    displayAux(os);
    return *this;
  }
  const Screen &display(ostream &os) const {
    displayAux(os);
    return *this;
  }
  pos size() const;

private:
  pos height = 0;
  pos width = 0;
  pos cursor = 0;
  string contents;

  void displayAux(ostream &os) const { os << contents; }
};

inline char Screen::get(pos r, pos c) const {
  pos row = r * width;
  return contents[row + c];
}

inline Screen &Screen::move(pos r, pos c) {
  pos row = r * width;
  cursor = row + c;
  return *this;
}

inline Screen &Screen::set(char c) {
  contents[cursor] = c;
  return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch) {
  contents[r * width + col] = ch;
  return *this;
}

inline Screen::pos Screen::size() const {
  return height * width;
} 

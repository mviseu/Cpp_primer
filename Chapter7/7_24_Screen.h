#pragma once

#include <string>

using std::string;

class Screen {
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

private:
  pos height = 0;
  pos width = 0;
  pos cursor = 0;
  string contents;
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
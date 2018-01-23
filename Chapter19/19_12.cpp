#pragma once

#include <string>
#include <iostream>

using std::string;

class Screen {
public:
  using pos = string::size_type;

  // implicitly inline
  char get() const { return contents[cursor]; }
  // defined outside the class body
  // get char at certain location
  char get(pos r, pos c) const;
  // move the cursor
  Screen &move(pos r, pos c);

  static const pos Screen::*pdata() {return &Screen::cursor;}

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


int main() {
  auto pcursor = Screen::pdata();
  Screen my_screen, *ptr_screen = &my_screen;
  std::cout << my_screen.*pcursor << std::endl;
  std::cout << ptr_screen->*pcursor << std::endl;
  return 0;
}
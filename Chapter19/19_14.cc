#include <string>
#include <iostream>

using std::string;

class Screen {
public:
  using pos = string::size_type;
  Screen(pos ht, pos wt, pos cur, const std::string con) : height(ht), width(wt), cursor(cur), contents(con) {}

  char get_cursor() const {return contents[cursor];}

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
  auto pmf = &Screen::get_cursor;
  //takes version of get with no arguments
  pmf = &Screen::get;
  Screen myScreen(5, 5, 20, "ThisIsALongStringThisIsALongStringThisIsALongStringThisIsALongString");
  std::cout << (myScreen.*pmf)() << std::endl;
 

  return 0;
}
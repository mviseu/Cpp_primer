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
  using CursorAction = char (Screen::*)() const;
  using HeightWidthAction = char (Screen::*)(Screen::pos, Screen::pos) const;
  using MoveAction = Screen &(Screen::*)(Screen::pos, Screen::pos);
  using StaticCursor = const Screen::pos Screen::*(*)();

  CursorAction getCursor = &Screen::get_cursor;
  CursorAction get = &Screen::get;
  HeightWidthAction getHeightWidth = &Screen::get;
  MoveAction move = &Screen::move;
  StaticCursor staticFnc = &Screen::pdata;

  // using the pointer to member access operators
  Screen myScreen(5, 5, 20, "ThisIsALongStringThisIsALongStringThisIsALongStringThisIsALongString"), *myScreenPtr = &myScreen;
  std::cout << (myScreen.*getCursor)() << std::endl;
  std::cout << (myScreen.*get)() << std::endl;
  std::cout << (myScreenPtr->*getHeightWidth)(0, 0) << std::endl;
  std::cout << (myScreenPtr->*move)(3, 3).get() << std::endl;
  std::cout << staticFnc() << std::endl;


  return 0;
}
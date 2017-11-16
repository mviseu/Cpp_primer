#pragma once
#include <iostream>

#pragma once

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::istream;
using std::ostream;

template <string::size_type H, string::size_type W> class Screen;
template <string::size_type H, string::size_type W> istream &operator>>(istream &is, Screen<H,W>&s);

template <string::size_type H, string::size_type W> class Screen {
public:
  friend istream &operator>> <H,W>(istream &is, Screen<H,W>&s);
  using pos = string::size_type;
  // constructors
  Screen() : contents(H * W, ' ') {}
  Screen(char c) : contents(H * W, c) {}

  // member functions
  // implicitly inline
  char get() const { return contents[cursor]; }
  // defined outside the class body
  // get char at certain location
  char get(pos r, pos c) const;
  // move the cursor
  //As per exercise, create copies of Screen instead of &
  Screen move(pos r, pos c);
  Screen set(char c);
  Screen set(pos r, pos col, char ch);
  Screen display(ostream &os) {
    displayAux(os);
    return *this;
  }
  const Screen display(ostream &os) const {
    displayAux(os);
    return *this;
  }

private:
  pos cursor = 0;
  string contents;

  void displayAux(ostream &os) const { os << contents; }

};

inline template <string::size_type H, string::size_type W> char Screen<H,W>::get(pos r, pos c) const {
  pos row = r * W;
  return contents[row + c];
}

inline template <string::size_type H, string::size_type W> Screen<H,W> Screen<H, W>::move(pos r, pos c) {
  pos row = r * W;
  cursor = row + c;
  return *this;
}

inline template <string::size_type H, string::size_type W> Screen<H,W> Screen<H, W>::set(char c) {
  contents[cursor] = c;
  return *this;
}

inline template <string::size_type H, string::size_type W> Screen<H,W> Screen<H, W>::set(pos r, pos col, char ch) {
  contents[r * W + col] = ch;
  return *this;
}

template <string::size_type H, string::size_type W> ostream &operator<<(ostream &os, const Screen<H,W>&s) {
	s.display(os);
	return os;
}

template <string::size_type H, string::size_type W> istream &operator>>(istream &is, Screen<H,W> &s) {
	is >> s.cursor >> s.contents;
	if(!is) {
		s = Screen<H,W>();
	}
	return is;
}
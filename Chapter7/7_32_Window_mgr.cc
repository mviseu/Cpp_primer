#include "7_32_Window_mgr.h"
#include "7_27_Screen.h"


void Window_mgr::clear(ScreenIndex i) {
  Screen &s = Screens[i];
  s.contents = string(s.width * s.height, ' ');
}

Window_mgr::Window_mgr() : Screens{Screen(24, 48, ' ')} {}
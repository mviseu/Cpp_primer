#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

// function declaration
inline const int fadd(const int i, const int j) { return i + j; }

inline const int fsubtract(const int i, const int j) { return i - j; }

inline const int fdivide(const int i, const int j) { return i / j; }

inline const int fmultiply(const int i, const int j) { return i * j; }

// pointer to function type
using falias = const int(const int, const int);

int main() {

  //& is not required since functions is converted automatically to pointer
  vector<falias *> vec = {fadd, fsubtract, fdivide, fmultiply};
  constexpr int a = -4;
  constexpr int b = 2;

  for (const auto &rpf : vec) {
   //* is not required since functions is converted automatically to pointer
    cout << rpf(a, b) << endl;
  }
  return 0;
}

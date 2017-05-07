#include <iostream>

// must include {} to enclose function body
double square(double x) { return x * x; }

int main() {
  auto result = square(3);

  std::cout << result << std::endl;
  return 0;
}
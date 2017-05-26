#include "7_58.h"

#include <vector>

using std::vector;

double Example::rate = 6.5;
//still defining Example::vecSize outside the class for extended use
const int Example::vecSize;
//initializing vec here since it is not const
vector<double> Example::vec(vecSize);
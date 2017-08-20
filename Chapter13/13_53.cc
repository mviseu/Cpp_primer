#include "HasPtr_13_53.h"

int main() {
	HasPtr hp("Hello");
	HasPtr hp3, hp4;
	hp3 = hp;
	hp4 = std::move(hp);

	return 0;
}
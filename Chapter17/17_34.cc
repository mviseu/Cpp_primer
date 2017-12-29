#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <string>

/*
*boolalpha
*noboolalpha
*dec
*hex
*oct
*noshowbase
*showbase

*noshowpoint
*showpoint
*noshowpos
*showpos

*uppercase
*nouppercase

*.precision()
*.precision(n)
*fixed
*scientifc
*hexfloat
*defaultfloat

*internal
*right
*left

*setfill(ch)
*setw(n)
*setprecision(n)
*setbase(b)

nounitbuf
unitbuf
*endl
ends
flush

*noskipws
*skipws

*/

int main() {
	std::cout << "Alpha bool" << std::endl;
	bool t(true);
	std::cout << std::boolalpha << t << std::endl;
	std::cout << std::noboolalpha << t << std::endl;

	std::cout << "Integral base notation, uppercase and show base" << std::endl;
	std::cout << std::dec << 10 << std::endl;
	std::cout << std::oct << 10 << std::endl;
	std::cout << std::hex << 10 << std::endl;
	std::cout << std::hex << std::uppercase << std::showbase << 10 << std::endl;
	std::cout << std::dec << std::nouppercase << std::noshowbase << std::endl;

	std::cout << "show and no show point" << std::endl;
	std::cout << std::showpoint << 10.0 << std::endl;
	std::cout << std::noshowpoint << 10.0 << std::endl;
	std::cout << std::showpos << 10.0 << std::endl;
	std::cout << std::noshowpos << 10.0 << std::endl;

	std::cout << "base" << std::endl;
	std::cout << std::setbase(8) << 10 << std::endl;
	std::cout << std::setbase(10) << 10 << std::endl;

	std::cout << "precision" << std::endl;
	std::cout << std::cout.precision() << std::endl;
	std::cout << std::cout.precision(12) << std::sqrt(2) << std::endl;
	std::cout << std::setprecision(6) << std::sqrt(2) << std::endl;

	std::cout << "formatting" << std::endl;
	std::cout << std::setw(25) << std::internal << -std::sqrt(2) << std::endl;
	std::cout << std::setw(25) << std::left << -std::sqrt(2) << std::endl;
	std::cout << std::setw(25) << std::right << -std::sqrt(2) << std::endl;
	std::cout << std::setw(25) << std::setfill('#') << -std::sqrt(2) << std::endl;
	std::cout << std::setw(25) << std::setfill(' ') << -std::sqrt(2) << std::endl;

	std::cout << "skipping whitespace" << std::endl;
	std::string message(" no 	skip whitespace" );
	std::istringstream s(message);
	s >> std::noskipws;
	char c;
	while(s >> c) {
		std::cout << c;
	}
	std::cout << std::endl;
	s >> std::skipws;
	s.clear();
	s.str(message);
	while(s >> c) {
		std::cout << c;
	}
	std::cout << std::endl;

	std::cout << "hi add null" << std::ends;
	std::cout << "hi flush" << std::flush;
	return 0;
}
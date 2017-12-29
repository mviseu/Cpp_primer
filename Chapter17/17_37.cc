#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>

int main() {
	std::ifstream file("unformatted_io_file");
	constexpr unsigned buffsize = 250;
	char sink[buffsize] = "";
	while(file.getline(sink, buffsize, ' ')) {
		std::cout.write(sink, strlen(sink)) << std::endl;
	}
	return 0;
}
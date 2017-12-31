#include <fstream>

int main() {
	std::fstream file("seek_file", std::fstream::out | std::fstream::in | std::fstream::ate);
	auto mark_end = file.tellg();
	file.seekg(0, std::fstream::beg);
	std::string line;
	std::size_t ctr(0);
	while(file && file.tellg() != mark_end && std::getline(file, line)) {
		auto mark = file.tellg();
		ctr += line.size() + 1;
		file.seekp(0, std::fstream::end);
		file << ctr;
		if(mark != mark_end) {
			file << " ";
		}
		file.seekg(mark);
	}
	file.seekp(0, std::fstream::end);
	file << std::endl;
	return 0;
}
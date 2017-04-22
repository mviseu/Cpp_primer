#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::strcat;
using std::strcpy;


//null terminator added automatically
const char London[] = "London";
const char Lisbon[] = "Lisbon";

int main() {

	//2 for space and null
	constexpr size_t size = strlen(London) + strlen(Lisbon) + 2;
	char Together[size] = {};

	
	strcpy(Together, London);
	strcat(Together, " ");
	strcat(Together, Lisbon);

	for(const auto &c : Together) {
		cout << c;
	}

	//Can print the array directly
	cout << Together << endl;

	return 0;
}

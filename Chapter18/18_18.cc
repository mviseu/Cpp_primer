#include <string>
#include <iostream>

namespace hs {
struct HasString {
	HasString(const std::string &m1) : mem1(m1) {}
	std::string mem1;
};


void swap(std::string &s1, std::string &s2) {
	std::cout << "string swap in hs namespace" << std::endl;
	std::swap(s1, s2);
}

}

namespace hi {

struct HasInt {
	int j = 0;
};

void swap(int &i1, int &i2) {
	std::cout << "int swap in hi namespace" << std::endl;
	std::swap(i1, i2);
}

}

void swap(hs::HasString &v1, hs::HasString &v2) {
	//using std::swap;
	std::cout << "swap(HasString &v1, HasString &v2)" << std::endl; 
	swap(v1.mem1, v2.mem1);
	std::cout << "End string swap" << std::endl;
	// swap remaining members
}

void swap(hi::HasInt &v1, hi::HasInt &v2) {
	//using std::swap;
	std::cout << "swap(HasInt &v1, HasInt &v2)" << std::endl; 
	std::swap(v1.j, v2.j);
	std::cout << "End int swap" << std::endl;
	// swap remaining members
}

int main() {
	hs::HasString hs1("hello"), hs2("goodbye");
	swap(hs1, hs2);
	hi::HasInt hi1, hi2;
	swap(hi1, hi2);

	return 0;
}


/*conclusions
1) Argument dependent lookup is taken into account 
2) Because string is in std:: namespace, swap is searched for in std:: (even without using declaration)
3) int is not in the std::namespace, so a using declaration or std:: prefix is necessary

Extra note: When using declaration is in scope and argument is of class type, the class swap version is searched for first.
Which means: argument lookup takes priority over using declaration
*/

#include <functional>
#include <iostream>

template <class T> int compare(const T &v1, const T &v2) {
	if(std::less<T>()(v1,v2)) {return -1;}
	if(std::less<T>()(v2,v1)) {return 1;}
	return 0;
}

template <typename T> void f1(T ab, T cd) {
	std::cout << ab << std::endl;
	std::cout << cd << std::endl;
}

template <typename T1, typename T2> void f2(T1 ab, T2 cd) {
	std::cout << ab << std::endl;
	std::cout << cd << std::endl;
}

template <typename T> T calc(T ab, int cd) {
	std::cout << ab << std::endl;
	std::cout << cd << std::endl;
	return ab;	
}



int main() {
	// legal integral promotion from char to int
	calc('c', 'c');
	char c  = 'c';
	f1(c, 'c');
	std::cout << compare("dad", "bye") << std::endl;


	int i = 0, j = 42, *p1 = &i, *p2 = &j;
	const int *cp1 = &i, *cp2 = &j;
	f1(p1, p2);
	f2(p1, p2);
	f1(cp1, cp2);
	f2(cp1, cp2);
	//conflicting types
	//f1(p1, cp1);
	f2(p1, cp1);


	return 0;
}
#include <string>

template <typename T> class Stack {
	using MyType = typename T::NonExistentType; 	
};


void f1(Stack<char>); // not instantiate

class Exercise {
	//Stack<int> si; // instantiates and generates error
	Stack<double> &rsd; // not instantiate
};

int main() {
	Stack<char> *sc; // not instantiate
	//f1(*sc); // instantiates, error
	//int iObj = sizeof(Stack<std::string>); // instantiates, error
	return 0;
}

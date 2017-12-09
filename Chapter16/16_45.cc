#include <vector>

template <typename T> void g(T&& val) {std::vector<T> v;}

int main() {
	//T is int
	//v is empty
	//g(42);

	//T is converted to int &
	//val is also int &
	//int reference elements of v must be initialized
	//error
	//int i = 1;
	//g(i);
	return 0;
}
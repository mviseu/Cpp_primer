template <typename T> void g(T && val);


int main() {
	int i = 0;
	const int ci = i;
	//template parameter becomes lvalue reference
	//template parameter T is int &
	// val type is int &

	//g(i);

	// template parameter type T is const i &
	// val type is const int &
	//g(ci);

	//T is int
	//val is int &&	
	//g(i * ci);

	// T is int&
	// val is int&
	//g(i = ci);
	return 0;
}
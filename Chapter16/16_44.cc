template <typename T> void g(T val);

template <typename Y> void g1(const Y &valY);

template <typename X> void g2(X &valX);


int main() {
	int i = 0;
	const int ci = i;
	// T is int
	// val is int
	//g(i);

	//top level consts are ignored
	// T and val are int
	//g(ci);

	//top level consts are ignored
	// T and val are int
	//g(ci);	
	//g(i * ci);

	//Y is int
	//valY is const int&
	//g1(i);

	// Y is int
	//valY is const int&
	//g1(ci);

	// Y is int
	//valY is const int&
	// lvalue const ref can be binded to rvalue
	//g1(ci * i);


	//X is int
	//valX is int&
	//g2(i);

	//X is const int
	//valX is const int &
	//g2(ci);

	//r value
	//not possible to bind an lvalue reference to rvalue
	//error
	//g2(i * ci);
	return 0;
}

int main() {
	int a = 3, b = 4;
	//c is int as is a
	decltype(a) c = a;

	//assignment yields reference to type of the left-hand operand. works exactly like ((a))
	decltype (a = b) d = a;

	return 0;
}
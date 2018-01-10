namespace Exercise {
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}

int ivar = 0;

// position 1
using Exercise::ivar; // disallowed in clang++ target of using declaration conflicts with declaration already in scope
using Exercise::dvar;
using Exercise::limit;

void manip() {
	double dvar = 3.1416; // hides Exercise::dvar
	int iobj = limit + 1; // uses Exercise::limit
	++ivar;
	++::ivar;
}

int main() {
	return 0;
}

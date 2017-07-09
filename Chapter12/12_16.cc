//attempt to assign/copy unique ptr to see how compiler diagnoses it
#include <memory>

using std::unique_ptr;

int main() {
	unique_ptr<int> pint(new int(42));
	//unique_ptr<int> pint_init(pint);
	//unique_ptr<int>pint_assign = pint;
	return 0;
}
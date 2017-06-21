#include <stack>
#include <fstream>

using std::ifstream;
using std::ofstream;
using std::stack;
using std::endl;


int main() {
	ifstream input("infile");
	ofstream output("outfile");
	if(!input) {
		return -1;
	}
	stack<char> stk;
	unsigned u = 0, posPar = 0;
	for(char c; input >> c; ++u) {
		stk.push(c);
		if(stk.top() == '(') {
			posPar = u;
		}
		if(stk.top() == ')' && posPar != 0) {
			stk.pop();
			while(u - posPar != 0) {
				stk.pop();
				--u;
			}
			stk.push('0');
		}

	}
	while (!stk.empty()) {
		output << stk.top();
		stk.pop();
	}
	output << endl;
	return 0;
}


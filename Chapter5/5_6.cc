#include <iostream>
#include <vector>
#include <string>


using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {

	const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
	unsigned grade;
	string lettergrade;

	cin >> grade;

	grade < 60 ? 
		(lettergrade = scores[0]) 
	: 
		(lettergrade = (scores[(grade - 50) / 10] +
		(grade != 100   ? 
			(grade % 10 > 7 ? 
				"+" 
			: 
				(grade % 10 < 3 ? 
					"-" 
				: 
					""
				)
			) 
		: 
			""
		)
	));


	cout << lettergrade << endl;

	return 0;
}
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
	int grade;

	cin >> grade;

	cout << (grade > 90 ? "High pass" : 
			 grade > 75 ? "Pass" :
			 grade > 60 ? "Low pass" : "Fail" 
			)
		 << endl;


	//Alternative

	if(grade >90) {

		cout << "High pass" << endl;

	} else {

		if (grade > 75) {

			cout << "Pass" << endl;

		} else {

			if (grade > 60) {

				cout << "Low pass" << endl;

			} else {

				cout << "Fail" << endl;
			}
		}

	} 

	return 0;
}

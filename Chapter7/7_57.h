#pragma once
#include <string>

using std::string;

class Account {
public:
	void calculate() {amount = amount * interestRate;}
	static double rate() {return interestRate;}
	static void rate(double newRate) {interestRate = newRate;}


private:
	string owner;
	double amount;
	static double interestRate;
	static double initRate();
};
#pragma once

#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;

class Book {

public:
	friend ostream &operator<<(ostream &os, const Book &B);
	friend istream &operator>>(istream &is, Book &B);
	//non delegating
	Book(const string &t, unsigned p, double w) :
	title(t), nrPages(p), width(w) {}

	//delegating
	//default
	Book() : Book("", 0, 0) {}
	//specifying only the title
	Book(const string &t) : Book(t, 0, 0) {}
	//specifying the title and the nr of pages
	Book(const string &t, unsigned p) : Book(t, p, 0) {}

private:
	string title;
	unsigned nrPages = 0;
	double width = 0;

};

ostream &operator<<(ostream &os, const Book &B) {
	os << B.title << " " << B.nrPages << " "
	   << B.width;
	return os;
}

istream &operator>>(istream &is, Book &B) {
	is >> B.title >> B.nrPages >> B.width;
	if(!is) {
		B = Book();
	}
	return is;
}


#pragma once

#include <string>

using std::string;

class Book {

public:
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
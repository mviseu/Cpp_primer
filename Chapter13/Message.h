#pragma once

#include <string>
#include <set>
#include <algorithm>
#include <iostream>
#include <iterator>


using std::string;
using std::set;
using std::ostream_iterator;
using std::cout;
using std::endl;

class Folder;

class Message {
	friend void swap(Message &m1, Message &m2);
	friend class Folder;
public:
	Message(const string &s = "") : contents(s) {}
	Message(const Message &);
	Message(Message &&m);
	Message &operator=(const Message &rhs);
	Message &operator=(Message &&rhs);

	void save(Folder &f);
	void remove(Folder &f);

	~Message();

	//testing
	void print_folders() const {
		ostream_iterator<Folder *> out(cout, " ");
		std::copy(folders.cbegin(), folders.cend(), out);
	}

private:
	string contents;
	set<Folder *>folders;
	void add_to_folders(const Message &m);
	void remove_from_folders();
	void move_from_folders(Message *m);
	void addFolder(Folder *f);
	void remFolder(Folder *f);

};

inline void swap(Message &m1, Message &m2) {
	using std::swap;
	m1.remove_from_folders();
	m1.add_to_folders(m2);
	m2.remove_from_folders();
	m2.add_to_folders(m1);
	swap(m1.contents, m2.contents);
	swap(m1.folders, m2.folders);
	cout << "using swap" << endl;
}
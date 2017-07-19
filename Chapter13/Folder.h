#pragma once

#include <set>
#include <algorithm>
#include <iostream>
#include <iterator>

using std::set;
using std::ostream_iterator;
using std::cout;

class Message;

class Folder {
	friend class Message;

public:
	Folder() {}
	Folder(const Folder &rhs);
	Folder &operator=(const Folder &rhs);
	~Folder();
	//testing
	void print_messages() const {
		ostream_iterator<Message *> out(cout, " ");
		std::copy(messages.cbegin(), messages.cend(), out);
	}

private:
	set<Message *> messages;
	void addMsg(Message *m);
	void remMsg(Message *m);
	void add_to_messages(const Folder &f);
	void remove_from_messages();
};
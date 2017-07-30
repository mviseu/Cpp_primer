#include "Message.h"
#include "Folder.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;


Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
	add_to_folders(m);
	cout << "Copy constructor" << endl;
}

Message::Message(Message &&m) : contents(std::move(m.contents)) {
	move_from_folders(&m);
	cout << "Move constructor" << endl;
}

Message &Message::operator=(const Message &rhs) {
	remove_from_folders();
	add_to_folders(rhs);
	contents = rhs.contents;
	folders = rhs.folders;
	cout << "copy assignment" << endl;
	return *this;
}

Message &Message::operator=(Message &&rhs) {
	if(this != &rhs) {
		remove_from_folders();
		contents = std::move(rhs.contents);
		move_from_folders(&rhs);
		cout << "move assignment" << endl;
	}
	return *this;
}

void Message::save(Folder &f) {
	folders.insert(&f);
	f.addMsg(this);
}

Message::~Message() {
	remove_from_folders();
}

void Message::remove(Folder &f) {
	folders.erase(&f);
	f.remMsg(this);

}

void Message::add_to_folders(const Message &m) {
	for(const auto &f : m.folders) {
		f -> addMsg(this);
	}
}

void Message::remove_from_folders() {
	for(const auto &f : folders) {
		f -> remMsg(this);
	}
}

void Message::move_from_folders(Message *m) {
	folders = std::move(m->folders);
	for(const auto &f : folders) {
		f -> remMsg(m);
		f -> addMsg(this);
	}
	m->folders.clear();
}

void Message::addFolder(Folder *f) {
	folders.insert(f);
}

void Message::remFolder(Folder *f) {
	folders.erase(f);
}
#include "Message.h"
#include "Folder.h"
#include <iostream>

using std::cout;
using std::endl;


Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
	add_to_folders(m);
}

Message &Message::operator=(const Message &rhs) {
	remove_from_folders();
	add_to_folders(rhs);
	contents = rhs.contents;
	folders = rhs.folders;
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

void Message::addFolder(Folder *f) {
	folders.insert(f);
}

void Message::remFolder(Folder *f) {
	folders.erase(f);
}